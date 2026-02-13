#include <cstdint>

#pragma once

// Structure to represent an sRGB color with 8 bits per channel
struct SRGB8
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    // Constructor
    SRGB8(uint8_t r, uint8_t g, uint8_t b);
};
