#include "Color/Conversion/toOKLab.h"
#include <cmath>

namespace Color::Conversion
{

// Helper method to convert LinearSRGB to OKLCH
//
// Values taken from conversion matrix:
// https://bottosson.github.io/posts/oklab/#converting-from-linear-srgb-to-oklab
OKLab toOKLab(LinearSRGB color)
{
    double l = 0.4122214708f * color.r + 0.5363325363f * color.g + 0.0514459929f * color.b;
    double m = 0.2119034982f * color.r + 0.6806995451f * color.g + 0.1073969566f * color.b;
    double s = 0.0883024619f * color.r + 0.2817188376f * color.g + 0.6299787005f * color.b;
    double l_ = std::cbrtf(l);
    double m_ = std::cbrtf(m);
    double s_ = std::cbrtf(s);

    return {
        0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,
        1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,
        0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_,
    };
}

OKLab toOKLab(OKLCH color)
{
    double a = color.c * std::cos(color.h * (M_PI / 180.0)); // Convert hue to radians
    double b = color.c * std::sin(color.h * (M_PI / 180.0)); // Convert hue to radians

    return {color.l, a, b};
}

} // namespace Color::Conversion
