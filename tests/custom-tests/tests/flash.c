#include "trap.h"
#define FLASH_START 0x30000000

int main() {
    for (int i = 0; i < 0x1000; i += sizeof(uint32_t)) {
        uint32_t data = *(uint32_t *)(FLASH_START + i);
        check(data == 123456);
    }
    return 0;
}
