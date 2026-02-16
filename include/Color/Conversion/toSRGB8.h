#pragma once

#include "Color/LinearSRGB.h"
#include "Color/OKLCH.h"
#include "Color/SRGB8.h"

namespace Color::Conversion
{

SRGB8 toSRGB8(OKLCH color);
SRGB8 toSRGB8(LinearSRGB color);

} // namespace Color::Conversion
