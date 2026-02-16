#include "Color/Conversion/toYs.h"
#include "Color/APCA/Constants.h"
#include <cmath>

namespace Color::Conversion
{

double toYs(SRGB8 color)
{
    auto calcYsColor = [](uint8_t colorVal, double LumScreen) -> double
    { return std::pow(colorVal / 255.0, Strc) * LumScreen; };

    return calcYsColor(color.r, LumScreenR) + calcYsColor(color.g, LumScreenG) +
           calcYsColor(color.b, LumScreenB);
}

} // namespace Color::Conversion
