#pragma once

#include <cstdint>

namespace Color
{

// Structure to represent and SRGB at 8-bit per channel
struct SRGB8
{
    uint8_t r; // Red channel [0-255]
    uint8_t g; // Green channel [0-255]
    uint8_t b; // Blue channel [0-255]

    // Constructor
    SRGB8(uint8_t r, uint8_t g, uint8_t b);
};

} // namespace Color
