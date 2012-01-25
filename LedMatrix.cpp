#include "LedMatrix.h"

CLedMatrix::CLedMatrix() {}

void CLedMatrix::init(int pixel_per_strip, int strips, boolean slalom)
{
    _len = pixel_per_strip;
    _strips = strips;
    _slalom = slalom;
    FastSPI_LED.setLeds(_strips*_len);
    _pixels = (CRGB*) FastSPI_LED.getRGBData();
}
void CLedMatrix::setColor(CRGB color)
{
    for (int i=0; i<_strips*_len; i++)
    _pixels[i] = color;
}
void CLedMatrix::set(int strip, int relpos, CRGB color)
{
    if (_slalom && strip %2) {
        relpos = _len - 1 -relpos;
    }
    _pixels[strip*_len + relpos] = color;
}
void CLedMatrix::blend(int strip, int relpos, CRGB color, float opacity)
{
    if (_slalom && strip %2) {
        relpos = _len - 1 - relpos;
    }
    CRGB &existing = _pixels[strip*_len + relpos];
    float oe = 1 - opacity;
    existing.r = min(255, oe * existing.r + opacity * color.r);
    existing.b = min(255, oe * existing.b + opacity * color.b);
    existing.g = min(255, oe * existing.g + opacity * color.g);
}
CRGB CLedMatrix::get(int strip, int relpos)
{
    if (_slalom && strip %2) {
        relpos = _len - 1 - relpos;
    }
    return _pixels[strip*_len+relpos];
}

void CLedMatrix::brighten(int column, int pos, CRGB color)
{
    CRGB o = get(column, pos);
    o.r = max(color.r, o.r);
    o.g = max(color.g,o.g);
    o.b = max(color.b, o.b);
    set(column, pos, o);
}