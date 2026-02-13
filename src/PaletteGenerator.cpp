#include "PaletteGenerator.h"
#include <cmath>

// Constructor
PaletteGenerator::PaletteGenerator(SRGB8 color, SRGB8 backgroundColor,
                                   std::vector<double> contrastSteps)
    : color(color), backgroundColor(backgroundColor), contrastSteps(contrastSteps) {};

// Helper method to convert LinearSRGB to OKLCH
//
// Values taken from conversion matrix:
// https://bottosson.github.io/posts/oklab/#converting-from-linear-srgb-to-oklab
OKLab PaletteGenerator::LinearSRGBtoOKLab(LinearSRGB color)
{
    float l = 0.4122214708f * color.r + 0.5363325363f * color.g + 0.0514459929f * color.b;
    float m = 0.2119034982f * color.r + 0.6806995451f * color.g + 0.1073969566f * color.b;
    float s = 0.0883024619f * color.r + 0.2817188376f * color.g + 0.6299787005f * color.b;

    float l_ = std::cbrtf(l);
    float m_ = std::cbrtf(m);
    float s_ = std::cbrtf(s);

    return {
        0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,
        1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,
        0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_,
    };
}

// Helper method to convert OKLab to OKLCH
//
// Values taken from conversion matrix:
// https://bottosson.github.io/posts/oklab/#the-oklab-color-space
OKLCH PaletteGenerator::OKLabToOKLCH(OKLab color)
{
    double c = std::sqrt(color.a * color.a + color.b * color.b);
    double h = std::atan2(color.b, color.a) * (180.0 / M_PI); // Convert radians to degrees
    if (h < 0)
        h += 360.0; // Ensure hue is in the range [0, 360)

    return {color.L, c, h};
}

// Generate the palette
std::vector<SRGB8> PaletteGenerator::generatePalette()
{

    LinearSRGB linearColor(color.r / 255.0, color.g / 255.0, color.b / 255.0);
    OKLab OKLabColor = LinearSRGBtoOKLab(linearColor);
    OKLCH OKLCHColor = OKLabToOKLCH(OKLabColor);
}
