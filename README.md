# drw.h
Is a simple drawing header only library that lets you to draw basic shapes.
It provides a way to save to image files to a `ppm` image format.

## Usage
First copy the header file to the root of you project.
Then add `#include "drw.h"` to use drw.h.

### drw\_fill\_color(uint8\_t *canvas, uint8_t[] rgb, int height, int width);
It fills the color of the canvas to the rgb color {255, 0, 0} rgb format.

