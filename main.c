#include <stdio.h>
#include <stdint.h>         // For uint8_t
#include "drw.h"

#define HEIGHT 135
#define WIDTH 240
uint8_t canvas[HEIGHT * WIDTH * 3];

void drw_line(uint8_t *canvas, uint8_t rgb[], int height, int width, int y1, int x1, int y2, int x2, int lw);
void drw_line(uint8_t *canvas, uint8_t rgb[], int height, int width, int y1, int x1, int y2, int x2, int lw) {
   // float dy = (float)y2 - (float)y1;
   // float dx = (float)x2 - (float)x1;
   // float slope = dy / dx;
   // printf("DEBUG: dy: %f\n", dy);
   // printf("DEBUG: dx: %f\n", dx);
   // printf("DEBUG: dy / dx: %f\n", slope);
   // if(dx <= 1.0f*lw) {
   //     for(int y = y1;y < y2;y++) {
   //         for(int x = x1 - lw/2;x < x1 + lw/2;x++) {
   //             drw_write_rgb(canvas, rgb, width, y, x);
   //         }
   //     }
   // }
   // for(int y = y1;y < y2;y++) {
   //     for(int x = x1;x < x2;x++) {
   //         if(((y - (slope*(float)x) + (float)lw) >= 0.1f) && ((y - (slope*(float)x) - (float)lw) <= 0.1f)) {
   //             drw_write_rgb(canvas, rgb, width, y, x);
   //         }
   //     }
   // }

}

int main() {
    uint8_t white[] = {255, 255, 255};
    uint8_t red[] = {255, 0, 0};
    uint8_t green[] = {0, 255, 0};
    uint8_t blue[] = {0, 0, 255};
    drw_fill_color(canvas, white,  HEIGHT, WIDTH);
    //drw_fill_gradient(canvas, green, red, HEIGHT, WIDTH);
    //drw_fill_rect(canvas, red, HEIGHT, WIDTH, (HEIGHT / 2) - 25, (WIDTH / 2) - 45, 50, 90);
    //drw_fill_circ(canvas, blue, HEIGHT, WIDTH, 45, 50, 30);
    drw_circ(canvas, red, HEIGHT, WIDTH, 45, 50, 30, 10);
    //drw_circ(canvas, blue, HEIGHT, WIDTH, 70, 50, 30, 50.1f);
    //int tx = WIDTH - 220;
    //int ty = HEIGHT - 50;
    //drw_line(canvas, blue, HEIGHT, WIDTH, 6, 6, ty, tx, 13);
    //drw_write_rgb(canvas, green, WIDTH, 6, 6);
    //drw_write_rgb(canvas, red, WIDTH, ty, tx);
    drw_save_to_ppm(canvas, "test.ppm", HEIGHT, WIDTH);
    return 0;
}


//drw_print_canvas(canvas, HEIGHT, WIDTH);
