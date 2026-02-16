#include "Color/Conversion/toSRGB8.h"
#include "Color/Conversion/toLinearSRGB.h"
#include "Color/Conversion/toOKLab.h"
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace Color::Conversion
{

SRGB8 toSRGB8(LinearSRGB color)
{
    auto convertChannel = [](double linearVal) -> uint8_t
    {
        // Clamping
        double c = std::clamp(linearVal, 0.0, 1.0);
        // Gamma Correction
        double srgbVal = (c <= 0.0031308) ? (12.92 * c) : (1.055 * std::pow(c, 1.0 / 2.4) - 0.055);

        return static_cast<uint8_t>(std::round(srgbVal * 255.0));
    };

    return {convertChannel(color.r), convertChannel(color.g), convertChannel(color.b)};
}

SRGB8 toSRGB8(OKLCH color)
{
    OKLab OKLabColor = toOKLab(color);
    LinearSRGB LinearSRGBColor = toLinearSRGB(OKLabColor);

    return toSRGB8(LinearSRGBColor);
}

} // namespace Color::Conversion
