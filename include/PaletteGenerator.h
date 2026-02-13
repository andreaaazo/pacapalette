#include "LinearSRGB.h"
#include "OKLCH.h"
#include "OKLab.h"
#include "SRGB8.h"
#include <vector>

#pragma once

class PaletteGenerator
{

public:
    // Constructor
    PaletteGenerator(SRGB8 color, SRGB8 backgroundColor, std::vector<double> contrastSteps);

    // Destructor
    ~PaletteGenerator();

    // Method to generate the palette
    std::vector<SRGB8> generatePalette();

private:
    SRGB8 color;                               // Color for which the palette will be generated
    SRGB8 backgroundColor;                     // Background color to check contrast against
    std::vector<double> contrastSteps;         // Contrast levels to generate the palette for
    OKLab LinearSRGBtoOKLab(LinearSRGB color); // Helper method to convert LinearSRGB to OKLab
    OKLCH OKLabToOKLCH(OKLab color);           // Helper method to convert OKLab to OKLCH
};
