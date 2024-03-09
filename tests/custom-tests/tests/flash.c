#include "trap.h"
#define SPI_START 0x10001000
#define FLASH_START 0x30000000

uint32_t bit_rev(uint32_t x) {
    uint32_t y = 0;
    for (int i = 0; i < 32; i++) {
        y = (y << 1) | (x & 1);
        x >>= 1;
    }
    return y;
}

uint32_t byte_rev(uint32_t x) {
    uint32_t y = 0;
    for (int i = 0; i < 4; i++) {
        y = (y << 8) | (x & 0xff);
        x >>= 8;
    }
    return y;
}

uint32_t flash_addr(uint32_t addr) {
    addr = (addr & 0x00ffffff) | 0x03000000;
    return bit_rev(addr);
}

uint32_t flash_data(uint32_t data) {
    return byte_rev(bit_rev(data));
}


uint32_t flash_read(uint32_t addr) {
    volatile const uint32_t *Rx1 = (uint32_t *)(SPI_START + 0x4);
    volatile uint32_t *Tx0 = (uint32_t *)SPI_START;
    volatile uint32_t *DIVIDER = (uint32_t *)(SPI_START + 0x14);
    volatile uint32_t *SS = (uint32_t *)(SPI_START + 0x18);
    volatile uint32_t *CTRL = (uint32_t *)(SPI_START + 0x10);

    *Tx0 = flash_addr(addr);
    *DIVIDER = 0x1;
    *SS = 0x1;

    // [31:14] [13] [12] [11] [10] [9] [8] [7] [6:0]
    // 0000000000000 0 0 1 0 0 1 0 1000000
    *CTRL = 0x940;

    while (((*CTRL) >> 8) & 1) {}

    return flash_data(*Rx1);
}

int main() {
    printf("flash read: %x\n", flash_read(FLASH_START + 0x4));
    return 0;
}
