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
    calculateContrastBounds();
}

double PaletteGenerator::getMaxContrastAchievable()
{
    Color::SRGB8 extremeColor =
        searchTowardsLight ? Color::SRGB8{255, 255, 255} : Color::SRGB8{0, 0, 0};

    return std::abs(Color::APCA::getContrast(extremeColor, backgroundColor));
}

void PaletteGenerator::calculateContrastBounds()
{

    if (colorOKLCH.l >= backgroundColorOKLCH.l)
    {
        minContrastBound = backgroundColorOKLCH.l;
        maxContrastBound = 1.0;
        searchTowardsLight = true;
    }
    else
    {
        minContrastBound = 0.0;
        maxContrastBound = backgroundColorOKLCH.l;
        searchTowardsLight = false;
    }
}

Color::SRGB8 PaletteGenerator::findColorForContrast(const double& targetContrast)
{
    double low = minContrastBound;
    double high = maxContrastBound;

    const double targetChroma = colorOKLCH.c;
    const double targetHue = colorOKLCH.h;

    Color::OKLCH bestFit = colorOKLCH;

    for (int i = 0; i < 100; i++)
    {
        double mid = low + (high - low) * 0.5;

        bestFit.l = mid;

        Color::Utils::fitInGamut(bestFit);

        Color::SRGB8 bestFitSRGB8 = Color::Conversion::toSRGB8(bestFit);

        double currentContrast = std::abs(Color::APCA::getContrast(bestFitSRGB8, backgroundColor));
        bestFit.c = targetChroma;
        bestFit.h = targetHue;

        if (currentContrast < targetContrast)
        {
            if (searchTowardsLight)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            if (searchTowardsLight)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
    }

    Color::Utils::fitInGamut(bestFit);

    return Color::Conversion::toSRGB8(bestFit);
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
