#pragma once

#include "Color/OKLCH.h"
#include "Color/SRGB8.h"
#include <vector>

class PaletteGenerator
{
public:
    PaletteGenerator(Color::SRGB8 color, Color::SRGB8 backgroundColor,
                     std::vector<double> contrastSteps);

    std::vector<Color::SRGB8> generatePalette();

private:
    Color::SRGB8 color;
    Color::SRGB8 backgroundColor;

    Color::OKLCH colorOKLCH;
    Color::OKLCH backgroundColorOKLCH;
    std::vector<double> contrastSteps;

    double minContrastBound;
    double maxContrastBound;
    bool searchTowardsLight;

    double getMaxContrastAchievable();
    void calculateContrastBounds();
    Color::SRGB8 findColorForContrast(const double& targetContrast);
};
