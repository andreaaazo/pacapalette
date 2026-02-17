#include "Color/Conversion/toLinearSRGB.h"
#include "Color/Conversion/toOKLab.h"
#include <cmath>
#include <iostream>

namespace Color::Conversion
{

// Helper method to convert OKLab to LinearSRGB
//
// Values taken from conversion:
// https://bottosson.github.io/posts/oklab/#the-oklab-color-space
LinearSRGB toLinearSRGB(OKLab color)
{

    double l_ = color.l + 0.3963377774 * color.a + 0.2158037573 * color.b;
    double m_ = color.l - 0.1055613458 * color.a - 0.0638541728 * color.b;
    double s_ = color.l - 0.0894841775 * color.a - 1.2914855480 * color.b;
    double l = l_ * l_ * l_;
    double m = m_ * m_ * m_;
    double s = s_ * s_ * s_;

    return {
        +4.0767416621 * l - 3.3077115913 * m + 0.2309699292 * s,
        -1.2684380046 * l + 2.6097574011 * m - 0.3413193965 * s,
        -0.0041960863 * l - 0.7034186147 * m + 1.7076147010 * s,
    };
}

LinearSRGB toLinearSRGB(OKLCH color)
{
    OKLab colorOKLab = toOKLab(color);

    return toLinearSRGB(colorOKLab);
}

LinearSRGB toLinearSRGB(SRGB8 color)
{
    auto u = [](double u) -> double
    {
        if (u <= 0.04045)
            return u / 12.92;
        return std::pow((u + 0.055) / 1.055, 2.4);
    };

    std::cout << u(color.r) << ":" << u(color.g) << ":" << u(color.b) << std::endl;

    return {u((double)color.r / 255.0), u((double)color.g / 255.0), u((double)color.b / 255.0)};
}

} // namespace Color::Conversion
