#include "Color/SRGB8.h"
#include "PaletteGenerator.h"
#include <iomanip>
#include <iostream>

// Helper per stampare un quadratino colorato nel terminale (ANSI Escape Codes)
// Funziona su Linux (Arch), Mac e terminali moderni.
void printColorPreview(const Color::SRGB8& c, double step)
{
    // Reset colore
    const char* reset = "\033[0m";

    // Set background color (ANSI: \033[48;2;R;G;Bm)
    std::cout << "\033[48;2;" << (int)c.r << ";" << (int)c.g << ";" << (int)c.b << "m";

    // Spazio vuoto colorato (il "quadratino")
    std::cout << "          ";

    // Reset per stampare il testo
    std::cout << reset;

    // Stampa i valori RGB e il target step
    std::cout << " Step " << std::setw(3) << step << ": "
              << "RGB(" << std::setw(3) << (int)c.r << ", " << std::setw(3) << (int)c.g << ", "
              << std::setw(3) << (int)c.b << ")" << std::endl;
}

int main()
{
    // 1. Definiamo lo scenario
    // Colore Base: Un bel Blu vivido (Dodger Blue)
    Color::SRGB8 brandColor{30, 144, 255};

    // Sfondo: Bianco (Light Mode)
    Color::SRGB8 background{255, 255, 255};

    // Step di contrasto desiderati (APCA)
    // 15 = Invisibile/Decorativo
    // 45 = Testo grande
    // 60 = Testo normale
    // 75 = Testo importante
    // 90 = Massimo contrasto
    std::vector<double> steps = {15.0, 30.0, 45.0, 60.0, 75.0, 90.0};

    std::cout << "--- Generazione Palette Enterprise ---\n";
    std::cout << "Base Color: RGB(" << (int)brandColor.r << "," << (int)brandColor.g << ","
              << (int)brandColor.b << ")\n\n";

    // 2. Istanziamo il generatore
    PaletteGenerator generator(brandColor, background, steps);

    // 3. Generiamo
    std::vector<Color::SRGB8> palette = generator.generatePalette();

    // 4. Output Visivo
    for (size_t i = 0; i < palette.size(); ++i)
    {
        printColorPreview(palette[i], steps[i]);
    }

    // --- PROVA DARK MODE ---
    std::cout << "\n--- Test Dark Mode (Sfondo Nero) ---\n";
    Color::SRGB8 darkBg{0, 0, 0};
    PaletteGenerator darkGen(brandColor, darkBg, steps);
    auto darkPalette = darkGen.generatePalette();

    for (size_t i = 0; i < darkPalette.size(); ++i)
    {
        printColorPreview(darkPalette[i], steps[i]);
    }

    return 0;
}
