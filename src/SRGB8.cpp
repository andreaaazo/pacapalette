#include "SRGB8.h"
#include <cstdint>
#include <stdexcept>

SRGB8::SRGB8(uint8_t r, uint8_t g, uint8_t b)
{
    // Validate that color components are within the valid range [0, 255]
    if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
        throw std::invalid_argument("Color components must be in the range [0, 255]");

    this->r = r;
    this->g = g;
    this->b = b;
}
