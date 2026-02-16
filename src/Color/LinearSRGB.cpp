#include "Color/LinearSRGB.h"
#include <stdexcept>

namespace Color
{

LinearSRGB::LinearSRGB(double r, double g, double b)
{
    // Validate that color components are within the valid range [0.0, 1.0]
    if (r < 0.0 || r > 1.0 || g < 0.0 || g > 1.0 || b < 0.0 || b > 1.0)
        throw std::invalid_argument("Values (r) (g) (b) must be in range [0, 1]");

    this->r = r;
    this->g = g;
    this->b = b;
}

} // namespace Color
