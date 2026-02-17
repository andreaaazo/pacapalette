#include "Color/Conversion/toOKLCH.h"
#include "Color/Conversion/toLinearSRGB.h"
#include "Color/Conversion/toOKLab.h"
#include <cmath>
#include <numbers>

namespace Color::Conversion
{

OKLCH toOKLCH(OKLab color)
{
    double c = std::sqrt(color.a * color.a + color.b * color.b);
    double h =
        std::atan2(color.b, color.a) * (180.0 / std::numbers::pi); // Convert radians to degrees

    return {color.l, c, h};
}

OKLCH toOKLCH(SRGB8 color)
{

    LinearSRGB colorLinearSRGB = toLinearSRGB(color);
    OKLab colorOKLab = toOKLab(colorLinearSRGB);
    return toOKLCH(colorOKLab);
}

} // namespace Color::Conversion
