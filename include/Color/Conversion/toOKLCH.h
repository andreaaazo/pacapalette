#pragma once

#include "Color/OKLCH.h"
#include "Color/OKLab.h"
#include "Color/SRGB8.h"

namespace Color::Conversion
{

OKLCH toOKLCH(OKLab color);
OKLCH toOKLCH(SRGB8 color);

} // namespace Color::Conversion
