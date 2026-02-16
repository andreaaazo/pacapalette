#include "Color/APCA/getContrast.h"
#include "Color/APCA/Constants.h"
#include "Color/Conversion/toYs.h"
#include <cmath>

namespace
{

static double Fsc(const double Yc)
{
    if (Yc < 0.0)
        return 0.0;

    if (Yc < Bthrsh)
        return Yc + std::pow(Bthrsh - Yc, Bclip);

    return Yc;
}

static double calcCw(const double Ybg, const double Ytxt)
{
    if (Ybg > Ytxt)
        return (std::pow(Ybg, Nbg) - std::pow(Ytxt, Ntx)) * Wscale;

    return (std::pow(Ybg, Rbg) - std::pow(Ytxt, Rtx)) * Wscale;
}

static double calcSapc(const double Cw)
{
    if (std::abs(Cw) < Wclamp)
        return 0.0;

    if (Cw > 0)
        return Cw - Woffset;

    return Cw + Woffset;
}

} // namespace

namespace Color::APCA
{

double getContrast(SRGB8 color, SRGB8 backgroundColor)
{
    double YsColor = Conversion::toYs(color);
    double YsBackgroundColor = Conversion::toYs(backgroundColor);
    double Ytxt = Fsc(YsColor);
    double Ybg = Fsc(YsBackgroundColor);
    double Cw = calcCw(Ybg, Ytxt);

    return calcSapc(Cw) * 100.0;
}

} // namespace Color::APCA
