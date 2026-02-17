#include "Color/Conversion/toRawLinearSRGB.h"
#include "Color/Conversion/toOKLab.h"

namespace Color::Conversion
{

// Helper method to convert OKLab to LinearSRGB
//
// Values taken from conversion:
// https://bottosson.github.io/posts/oklab/#the-oklab-color-space
RawLinearSRGB toRawLinearSRGB(const OKLab& color)
{
    double l_ = color.l + 0.3963377774f * color.a + 0.2158037573f * color.b;
    double m_ = color.l - 0.1055613458f * color.a - 0.0638541728f * color.b;
    double s_ = color.l - 0.0894841775f * color.a - 1.2914855480f * color.b;
    double l = l_ * l_ * l_;
    double m = m_ * m_ * m_;
    double s = s_ * s_ * s_;

    return {
        +4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
        -1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
        -0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s,
    };
}

RawLinearSRGB toRawLinearSRGB(const OKLCH& color)
{
    OKLab colorOKLab = toOKLab(color);

    return toRawLinearSRGB(colorOKLab);
}

} // namespace Color::Conversion
