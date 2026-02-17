#pragma once

#include "Color/LinearSRGB.h"
#include "Color/OKLCH.h"
#include "Color/OKLab.h"
#include "Color/SRGB8.h"

namespace Color::Conversion
{

LinearSRGB toLinearSRGB(OKLCH color);
LinearSRGB toLinearSRGB(OKLab color);
LinearSRGB toLinearSRGB(SRGB8 color);

} // namespace Color::Conversion
