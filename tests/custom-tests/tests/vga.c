#include "trap.h"

#define VGA_START 0x21000000
#define ROW 480
#define COL 640

int main() {
    uint8_t *vga = (uint8_t *)VGA_START;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            for (int k = 0; k < 3; k++) {
                vga[i * COL * 3 + j * 3 + k] = (i + j + k) % 256;
            }
        }
    }

    printf("VGA Output Done.\n");

    while (1);

    return 0;
}
