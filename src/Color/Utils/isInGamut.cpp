#include "Color/Utils/isInGamut.h"
#include "Color/Conversion/toLinearSRGB.h"

namespace Color::Utils
{

bool isInGamut(const OKLCH& color)
{
    LinearSRGB colorLinearSRGB = Conversion::toLinearSRGB(color);

    return (colorLinearSRGB.r >= 0.0 && colorLinearSRGB.r <= 1.0) &&
           (colorLinearSRGB.g >= 0.0 && colorLinearSRGB.g <= 1.0) &&
           (colorLinearSRGB.b >= 0.0 && colorLinearSRGB.b <= 1.0);
}

} // namespace Color::Utils
