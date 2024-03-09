#include "trap.h"

#define SPI_START 0x10001000

int main() {
    volatile const uint32_t *Rx0 = (uint32_t *)SPI_START;
    volatile uint32_t *Tx0 = (uint32_t *)SPI_START;
    volatile uint32_t *DIVIDER = (uint32_t *)(SPI_START + 0x14);
    volatile uint32_t *SS = (uint32_t *)(SPI_START + 0x18);
    volatile uint32_t *CTRL = (uint32_t *)(SPI_START + 0x10);

    *Tx0 = 0x0000000f;
    *DIVIDER = 0x1;
    *SS = 0x80;

    // [31:14] [13] [12] [11] [10] [9] [8] [7] [6:0]
    // 0000000000000 0 0 1 0 0 1 0 0010000
    *CTRL = 0x910;

    while (((*CTRL) >> 8) & 1) {}

    check((*Rx0) >> 8 == 0xf0);

    return 0;
}
