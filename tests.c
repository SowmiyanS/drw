#include <stdint.h>
#include "drw.h"

#define HEIGHT 600
#define WIDTH 400

uint8_t canvas[HEIGHT*WIDTH*3];

int main(int argc, char *argv[]) {
    drw_fill_color(canvas, white, HEIGHT, WIDTH);
    drw_save_to_ppm(canvas, filename, HEIGHT, WIDTH);
    return 0;
}
