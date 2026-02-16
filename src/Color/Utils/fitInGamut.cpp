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
    OKLCH targetColor = color;

    for (int i = 0; i < 100; i++)
    {

        double mid = low + (high - low) / 2.0;
        targetColor.c = mid;

        if (isInGamut(targetColor))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
}

} // namespace Color::Utils
