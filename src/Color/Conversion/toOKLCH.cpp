#include "Color/Conversion/toOKLCH.h"
#include "Color/Conversion/toOKLab.h"
#include <cmath>

namespace Color::Conversion
{

OKLCH toOKLCH(OKLab color)
{
    double c = std::sqrt(color.a * color.a + color.b * color.b);
    double h = std::atan2(color.b, color.a) * (180.0 / M_PI); // Convert radians to degrees

    return {color.l, c, h};
}

OKLCH toOKLCH(SRGB8 color)
{
    LinearSRGB linearColor(color.r / 255.0, color.g / 255.0, color.b / 255.0);
    OKLab OKLabColor = toOKLab(linearColor);
    return toOKLCH(OKLabColor);
}

} // namespace Color::Conversion
