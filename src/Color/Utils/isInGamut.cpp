#include "Color/Utils/isInGamut.h"
#include "Color/Conversion/toRawLinearSRGB.h"

namespace Color::Utils
{

bool isInGamut(const OKLCH& color)
{
    RawLinearSRGB colorRawLinearSRGB = Conversion::toRawLinearSRGB(color);

    return (colorRawLinearSRGB.r >= 0.0 && colorRawLinearSRGB.r <= 1.0) &&
           (colorRawLinearSRGB.g >= 0.0 && colorRawLinearSRGB.g <= 1.0) &&
           (colorRawLinearSRGB.b >= 0.0 && colorRawLinearSRGB.b <= 1.0);
}

} // namespace Color::Utils
