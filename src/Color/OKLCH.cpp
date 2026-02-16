#include "Color/OKLCH.h"
#include <cmath>
#include <stdexcept>

namespace Color
{

OKLCH::OKLCH(double l, double c, double h)
{
    // Chroma must be non-negative
    if (c < 0.0)
        throw std::invalid_argument("Chroma (c) must be non-negative");

    // Luminance must be in [0-1]
    if (0.0 > l || l > 1.0)
        throw std::invalid_argument("Luminance (l) must be in [0,1]");

    // Normalize hue to [0, 360)
    double hNormalized = std::fmod(h, 360.0);

    if (hNormalized < 0.0)
        hNormalized += 360.0;

    this->l = l;
    this->c = c;
    this->h = hNormalized;
}

} // namespace Color
