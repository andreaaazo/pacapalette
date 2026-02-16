#pragma once

namespace Color
{

struct OKLab
{
    double l; // Lightness
    double a; // a component
    double b; // b component

    OKLab(double l, double a, double b);
};

} // namespace Color
