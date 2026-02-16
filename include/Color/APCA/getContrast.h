#pragma once

#include "Color/SRGB8.h"

namespace Color::APCA
{

double getContrast(const SRGB8& color, const SRGB8& backgroundColor);
}
