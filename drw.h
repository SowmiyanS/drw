#ifndef DRW_H
#define DRW_H

void drw_fill_color(uint8_t *canvas, uint8_t rgb[], int height, int width);
void drw_fill_gradient(uint8_t *canvas, uint8_t rgb_start[], uint8_t rgb_end[], int height, int width);
void drw_write_rgb(uint8_t *canvas, uint8_t rgb[], int width, int y, int x);
void drw_print_canvas(uint8_t *canvas, int height, int width);
void drw_fill_rect(uint8_t *canvas, uint8_t rgb[], int height, int width, int ry, int rx, int bredth, int length);
//void drw_rect(uint8_t *canvas, uint8_t rgb[], int height, int width, int ry, int rx, int bredth, int length);
void drw_fill_circ(uint8_t *canvas, uint8_t rgb[], int height, int width, int cy, int cx, float radius);
void drw_circ(uint8_t *canvas, uint8_t rgb[], int height, int width, int cy, int cx, float radius, float lw);
int drw_save_to_ppm(uint8_t *canvas, const char *filename, int height, int width);
int drw_abs(int n);

void drw_fill_color(uint8_t *canvas, uint8_t rgb[], int height, int width) {
    for(int y = 0;y < height;y++) {
        for(int x = 0;x < width;x++) {
            //for(int c = 0;c < 3;c++) {
            //    canvas[y*width*3 + x*3 + c] = rgb[c];
            //}
            drw_write_rgb(canvas, rgb, width, y, x);
        }
    }
}

void drw_fill_gradient(uint8_t *canvas, uint8_t rgb_start[], uint8_t rgb_end[], int height, int width) {
    uint8_t rgb_crnt[] = {0, 0, 0};
    int d0 = rgb_start[0] - rgb_end[0];
    int d1 = rgb_start[1] - rgb_end[1];
    int d2 = rgb_start[2] - rgb_end[2];
    rgb_crnt[0] = rgb_start[0];
    rgb_crnt[1] = rgb_start[1];
    rgb_crnt[2] = rgb_start[2];
    for(int y = 0;y < height;y++) {
        rgb_crnt[0] += (uint8_t)(d0/height);
        rgb_crnt[1] += (uint8_t)(d1/height);
        rgb_crnt[2] += (uint8_t)(d2/height);
        for(int x = 0;x < width;x++) {
            drw_write_rgb(canvas, rgb_crnt, width, y, x);
        }
    }
}

void drw_write_rgb(uint8_t *canvas, uint8_t rgb[], int width, int y, int x) {
    for(int c = 0;c < 3;c++) {
        canvas[y*width*3 + x*3 + c] = rgb[c];
    }
}

void drw_print_canvas(uint8_t *canvas, int height, int width) {
    for(int y = 0;y < height;y++) {
        for(int x = 0;x < width;x++) {
            for(int c = 0;c < 3;c++) {
                printf("%d ",canvas[y*width*3 + x*3 + c]);
            }
            printf("  ");
        }
        printf("\n");
    }
}

void drw_fill_rect(uint8_t *canvas, uint8_t rgb[], int height, int width, int ry, int rx, int bredth, int length) {
    for(int y = ry;y < ry + bredth;y++) {
        for(int x = rx;x < rx + length;x++) {
            drw_write_rgb(canvas, rgb, width, y, x);
        }
    }
}

//void drw_rect(uint8_t *canvas, uint8_t rgb[], int height, int width, int ry, int rx, int bredth, int length) {
//    for(int y = ry;y < ry + bredth;y++) {
//        for(int x = rx;x < rx + length;x++) {
//            drw_write_rgb(canvas, rgb, width, y, x);
//        }
//    }
//}

void drw_fill_circ(uint8_t *canvas, uint8_t rgb[], int height, int width, int cy, int cx, float radius) {
    for(float y = cy - radius;y <= cy + radius;y++) {
        for(float x = cx - radius;x <= cx + radius;x++) {
            if(((cy - y)*(cy - y))+((cx - x)*(cx - x)) <= radius*radius) {                              // Calculate the distance between circle's center and current point
                drw_write_rgb(canvas, rgb, width, (int)y, (int)x);
            }
        }
    }
}

void drw_circ(uint8_t *canvas, uint8_t rgb[], int height, int width, int cy, int cx, float radius, float lw) {
    for(float y = cy - radius;y <= cy + radius;y++) {
        for(float x = cx - radius;x <= cx + radius;x++) {
            if( ((((cy - y)*(cy - y))+((cx - x)*(cx - x))) <= (radius*radius)+lw) && ((((cy - y)*(cy - y))+((cx - x)*(cx - x))) >= (radius*radius)-lw) ) {                              // Calculate the distance between circle's center and current point
                drw_write_rgb(canvas, rgb, width, (int)y, (int)x);
            }
        }
    }
}

int drw_save_to_ppm(uint8_t *canvas, const char *filename, int height, int width) {
    int exit_code = 0;
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("ERROR: failed to open file: %s\n", filename);
        exit_code = -1;
        goto defer_return;
    }
    else {
        printf("INFO: file opened: %s\n", filename);
    }
    
    //write p3 height width range header
    fprintf(fp, "P3 %d %d %d\n", width, height, 255);
    uint8_t state = 0;
    for(int y = 0;y < height;y++) {
        for(int x = 0;x < width;x++) {
            if(state == 1) {
                fprintf(fp, "\n");
            }
            fprintf(fp, "%d %d %d", canvas[y*width*3 + x*3 + 0], canvas[y*width*3 + x*3 + 1], canvas[y*width*3 + x*3 + 2]);
            state = 1;
        }
        fprintf(fp, "\n");
    }

defer_return:
    if(fp) fclose(fp);
    return exit_code;
}

int drw_abs(int n) {
    if(n < 0) return -1 * n;
    return n;
}

#endif //DRW_H
