#pragma once

#include "Color/LinearSRGB.h"
#include "Color/OKLCH.h"
#include "Color/OKLab.h"

namespace Color::Conversion
{

OKLab toOKLab(LinearSRGB color);
OKLab toOKLab(OKLCH color);

} // namespace Color::Conversion
