#ifndef LedMatrix_h
#define LedMatrix_h

#include "WProgram.h"
#include <FastSPI_LED.h>

/**
 * The led matrix library class.
 *
 * See the README in this folder for an introduction.
 *
 * NOTE: i tried extending CFastSPI_LED but somehow i never got any pixels lighted with that.
 */

/*
 * Sometimes chipsets wire in a backwards sort of way. Find out what is right for your strips
 * and select the right struct from below.
 */
//struct CRGB { unsigned char r; unsigned char g; unsigned char b; };
//struct CRGB { unsigned char b; unsigned char r; unsigned char g; };
struct CRGB { unsigned char b; unsigned char g; unsigned char r; };

class CLedMatrix
{
  public:
    CLedMatrix();
    /**
     * Create the led matrix.
     * This initializes FastSPI_LED with an array of length
     * pixel_per_strip * strips
     *
     * @param pixel_per_strip the number of pixels each strip has
     * @param strips the number of strips that form the matrix
     * @param slalom whether to invert every even
     */
    void init(int pixel_per_strip, int strips, boolean slalom);
    /**
     * Set the whole matrix to the color
     */
    void setColor(CRGB color);
    /**
     * Set the pixel at position relpos in strip to the color.
     *
     * If you use slalom and strip is an odd number (strips counted from 0),
     * relpos is inverted so it is always calculated from the top of your
     * grid.
     *
     * @param strip which strip to address, 0 based address
     * @param relpos position of the pixel relative to this strip
     * @param color the desired color for the pixel
     */
    void set(int strip, int relpos, CRGB color);
    /**
     * The same as set, but only update pixel colors where the supplied color
     * is lighter than the existing one.
     */
    void lighten(int strip, int relpos, CRGB color);
    /**
     * The same as set, but with the possibility for opacity to build the
     * average color
     *
     * @param opacity a value between 0 and 1
     */
    void blend(int strip, int relpos, CRGB color, float opacity);

    CRGB get(int strip, int relpos);
    /**
     * Same as set, but only for color parts that are brighter
     */
    void brighten(int strip, int relpos, CRGB color);
    //void darken(int strip, int relpos, CRGB color);
    /**
     * Set pixel to average of current color and parameter color
     */
    //void average(int strip, int relpos, CRGB color);

    /**
     * expose the p_mData as CRGB
     */
    CRGB* _pixels;

  private:
    CLedMatrix(CLedMatrix &m); //disable copy constructor
    int _len;
    int _strips;
    boolean _slalom;
};

#endif
