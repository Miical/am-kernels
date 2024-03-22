#include "trap.h"

#define PS2_ADDR 0x10011000

int main() {
    volatile uint8_t *keyboard = (uint8_t *)PS2_ADDR;

    while (1) {
        uint8_t ch = *keyboard;
        if (ch != 0) {
            printf("Got (kbd): %x\n", ch);
        }
    }
}
