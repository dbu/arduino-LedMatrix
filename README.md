This little [Arduino](http://www.arduino.cc/) library adds syntactic sugar around the fastspi library with two dimensional layouts of LEDs.

# Description

The LedMatrix class wraps around the FastSPI_LED instance, taking care of initializing FastSPI_LED
with the right number of pixels.

It handles two dimensional layouts of leds. To keep wiring short, you might want to wire your
LED strips in S lines, meaning every second strip is ordered inversly.
The names assume your matrix consists of vertical strips. With the origin at top-left,
the strip number is your x coordinate and the relative position in the y coordinate.

# Install

To install, put the [FastSPI_LED](http://code.google.com/p/fastspi/) library into the library folder of your arduino sketchbook.
Then add this repository to your sketchbook. Either use

    git clone git://github.com/dbu/arduino-LedMatrix.git

Or just <a href="https://github.com/dbu/arduino-LedMatrix/zipball/master">download the zip file</a>.

Now restart your Arduino library and click Sketch > Import library... and import both FastSPI_LED and LedMatrix.
The first lines in your sketch should now be

    #include <FastSPI_LED.h>
    #include <LedMatrix.h>

# Usage

Instead of FastSPI_LED.setLeds(), call LedMatrix.init(LENGTH, STRIPS, slalom)
then go through the normal bootstrap of FastSPI_LED.

See LedMatrix.h for doc about the functions you have available.

To see some sample code, have a look at the [led-globe](https://github.com/dbu/arduino-led-globe) project.