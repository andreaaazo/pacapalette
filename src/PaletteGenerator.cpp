#include "PaletteGenerator.h"
#include "Color/APCA/getContrast.h"
#include "Color/Conversion/toOKLCH.h"
#include "Color/Conversion/toSRGB8.h"
#include "Color/OKLCH.h"
#include "Color/SRGB8.h"
#include "Color/Utils/fitInGamut.h"
#include <algorithm>
#include <cstdlib>

PaletteGenerator::PaletteGenerator(Color::SRGB8 color, Color::SRGB8 backgroundColor,
                                   std::vector<double> contrastSteps)
    : color(color), backgroundColor(backgroundColor), colorOKLCH(Color::Conversion::toOKLCH(color)),
      backgroundColorOKLCH(Color::Conversion::toOKLCH(backgroundColor)),
      contrastSteps(contrastSteps)
{
    calculateSearchDirection();
}

double PaletteGenerator::getMaxContrastAchievable()
{
    Color::SRGB8 extremeColor =
        searchTowardsLight ? Color::SRGB8{255, 255, 255} : Color::SRGB8{0, 0, 0};

    return std::abs(Color::APCA::getContrast(extremeColor, backgroundColor));
}

void PaletteGenerator::calculateSearchDirection()
{

    if (colorOKLCH.l >= backgroundColorOKLCH.l)
    {
        searchTowardsLight = true;
    }
    else
    {
        searchTowardsLight = false;
    }
}

Color::SRGB8 PaletteGenerator::findColorForContrast(const double& targetContrast)
{
    double low = 0.0;
    double high = 1.0;

    const double targetChroma = colorOKLCH.c;
    const double targetHue = colorOKLCH.h;

    Color::OKLCH bestColorFound = colorOKLCH;

    double minDiff = 1000.0;

    for (int i = 0; i < 1000; i++)
    {
        double mid = low + (high - low) * 0.5;

        Color::OKLCH candidate{mid, targetChroma, targetHue};

        Color::Utils::fitInGamut(candidate);

        Color::SRGB8 candidateSRGB = Color::Conversion::toSRGB8(candidate);
        double currentContrast = std::abs(Color::APCA::getContrast(candidateSRGB, backgroundColor));

        double diff = std::abs(currentContrast - targetContrast);

        if (diff < minDiff)
        {
            minDiff = diff;
            bestColorFound = candidate;
        }

        if (currentContrast < targetContrast)
        {
            if (searchTowardsLight)
                low = mid;
            else
                high = mid;
        }
        else
        {
            if (searchTowardsLight)
                high = mid;
            else
                low = mid;
        }

        if (minDiff < 0.001)
            break;
    }

    return Color::Conversion::toSRGB8(bestColorFound);
}

std::vector<Color::SRGB8> PaletteGenerator::generatePalette()
{
    std::vector<Color::SRGB8> palette;
    double maxContrastAchievable = getMaxContrastAchievable();

    for (auto step : contrastSteps)
    {
        double targetContrast = std::min(step, maxContrastAchievable);
        palette.push_back(findColorForContrast(targetContrast));
    }

    return palette;
}
