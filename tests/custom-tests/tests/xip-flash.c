#include "trap.h"
#define FLASH_START 0x30000000

int main() {
    for (int addr = 0; addr < 0x18; addr += 0x4) {
        uint32_t data = *(int *)(FLASH_START + addr);
        printf("flash read addr = %x, data = %x\n", FLASH_START + addr, data);
    }

    return 0;
}
