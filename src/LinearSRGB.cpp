#include "LinearSRGB.h"
#include <stdexcept>

// Constructor
LinearSRGB::LinearSRGB(double r, double g, double b)
{
    // Validate that color components are within the valid range [0.0, 1.0]
    if (r < 0.0 || r > 1.0 || g < 0.0 || g > 1.0 || b < 0.0 || b > 1.0)
        throw std::invalid_argument("Color components must be in the range [0.0, 1.0]");

    this->r = r;
    this->g = g;
    this->b = b;
}
