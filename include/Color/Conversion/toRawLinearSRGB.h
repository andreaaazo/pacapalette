#pragma once

#include "Color/OKLCH.h"
#include "Color/OKLab.h"
#include "Color/RawLinearSRGB.h"

namespace Color::Conversion
{

RawLinearSRGB toRawLinearSRGB(const OKLab& color);

RawLinearSRGB toRawLinearSRGB(const OKLCH& color);

} // namespace Color::Conversion
