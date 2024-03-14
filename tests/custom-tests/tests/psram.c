#include "trap.h"
#define SIZE 4096
#define PSRAM_START 0x80000000

int main() {
    for (int i = 0; i < SIZE; i += 0x1) {
        volatile char *addr = (char *)(PSRAM_START + i);
        *addr = i;
        check(*addr == (char)i);
    }
    for (int i = 0; i < SIZE; i += 0x4) {
        volatile int *addr = (int *)(PSRAM_START + i);
        *addr = i;
        check(*addr == (int)i);
    }

    return 0;
}
