#pragma once

namespace Color
{

struct OKLCH
{
    double l; // Lightness
    double c; // Chroma
    double h; // Hue

    OKLCH(double l, double c, double h);
};

} // namespace Color
