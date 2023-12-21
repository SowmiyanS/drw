#include <stdio.h>  // For sprintf()
#include <stdint.h> // For uint8_t
#include <stdlib.h> // For exit()
#include "drw.h"
 
#define HEIGHT 600
#define WIDTH 800


// Global colors
uint8_t WHITE[] = {255, 255, 255};
uint8_t RED[] = {255, 0, 0};
// Global canvas
uint8_t canvas[HEIGHT*WIDTH*3];
// Global imagestring
char IMAGENAME[50];


void test_rectangle(char *argv[]);


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("ERROR: missing arguments\n\tusage: %s <output-path>\n", argv[0]);
        exit(1);
    }
    else {
        printf("INFO: using %s as the output path for generating images.\n", argv[1]);
    }

    printf("INFO: generating canvas...\n");
    drw_fill_color(canvas, WHITE, HEIGHT, WIDTH);


    test_rectangle(argv);



    printf("INFO: successfully exited.\n");

    return 0;
}

void test_rectangle(char *argv[]) {
    drw_fill_rect(canvas, RED, HEIGHT, WIDTH, HEIGHT/2 - 270/2, WIDTH/2 - 540/2, 270, 540);
    sprintf(IMAGENAME, "%s/test002.ppm", argv[1]); // Write the file path to global char * using sprintf for format specification.
    drw_save_to_ppm(canvas, IMAGENAME, HEIGHT, WIDTH);
    printf("INFO: generated rectangle %s\n", IMAGENAME);
}
