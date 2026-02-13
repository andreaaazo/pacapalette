#pragma once

// Structure to represent a linear sRGB color 0.0 to 1.0
struct LinearSRGB
{
    double r; // Red channel (0.0 to 1.0)
    double g; // Green channel (0.0 to 1.0)
    double b; // Blue channel (0.0 to 1.0)

    // Constructor
    LinearSRGB(double r, double g, double b);
};
