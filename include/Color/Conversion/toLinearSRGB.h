#pragma once

#include "Color/LinearSRGB.h"
#include "Color/OKLCH.h"
#include "Color/OKLab.h"

namespace Color::Conversion
{

LinearSRGB toLinearSRGB(OKLCH color);
LinearSRGB toLinearSRGB(OKLab color);

} // namespace Color::Conversion
