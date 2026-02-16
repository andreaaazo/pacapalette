#include "Color/SRGB8.h"
#include <stdexcept>

namespace Color
{

SRGB8::SRGB8(uint8_t r, uint8_t g, uint8_t b)
{

    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
        throw std::invalid_argument("Values (r) (g) (b) must be in range [0, 255]");

    this->r = r;
    this->g = g;
    this->b = b;
};

} // namespace Color
