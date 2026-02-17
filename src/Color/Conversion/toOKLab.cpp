#include "Color/Conversion/toOKLab.h"
#include <cmath>
#include <numbers>

namespace Color::Conversion
{

// Helper method to convert LinearSRGB to OKLCH
//
// Values taken from conversion matrix:
// https://bottosson.github.io/posts/oklab/#converting-from-linear-srgb-to-oklab
OKLab toOKLab(LinearSRGB color)
{
    double l = 0.4122214708 * color.r + 0.5363325363 * color.g + 0.0514459929 * color.b;
    double m = 0.2119034982 * color.r + 0.6806995451 * color.g + 0.1073969566 * color.b;
    double s = 0.0883024619 * color.r + 0.2817188376 * color.g + 0.6299787005 * color.b;
    double l_ = std::cbrt(l);
    double m_ = std::cbrt(m);
    double s_ = std::cbrt(s);

    return {
        0.2104542553 * l_ + 0.7936177850 * m_ - 0.0040720468 * s_,
        1.9779984951 * l_ - 2.4285922050 * m_ + 0.4505937099 * s_,
        0.0259040371 * l_ + 0.7827717662 * m_ - 0.8086757660 * s_,
    };
}

OKLab toOKLab(OKLCH color)
{
    double a = color.c * std::cos(color.h * (std::numbers::pi / 180.0)); // Convert hue to radians
    double b = color.c * std::sin(color.h * (std::numbers::pi / 180.0)); // Convert hue to radians

    return {color.l, a, b};
}

} // namespace Color::Conversion
