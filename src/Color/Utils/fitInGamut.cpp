#include "Color/Utils/fitInGamut.h"
#include "Color/Utils/isInGamut.h"

namespace Color::Utils
{

void fitInGamut(OKLCH& color)
{
    if (isInGamut(color))
    {
        return;
    }

    double low = 0.0;
    double high = color.c;

    constexpr double EPSILON = 0.000000001;

    while ((high - low) > EPSILON)
    {

        double mid = low + (high - low) / 2.0;
        color.c = mid;

        if (isInGamut(color))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    color.c = low;
}

} // namespace Color::Utils
