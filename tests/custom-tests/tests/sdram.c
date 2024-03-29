#include "trap.h"
#define SIZE 0x02000 // 32MB
#define PSRAM_START 0xa0000000

int main() {
    printf("sdram test\n");
    printf("1 byte read/write test\n");
    for (int i = 0; i < SIZE; i += 0x1) {
        volatile char *addr = (char *)(PSRAM_START + i);
        *addr = i;
        check(*addr == (char)i);
        if (i % 0x1000 == 0)
            printf("progress: %d%%\n", i * 100 / SIZE);
    }

    printf("1 byte read test\n");
    for (int i = 0; i < SIZE; i += 0x1) {
        volatile char *addr = (char *)(PSRAM_START + i);
        check(*addr == (char)i);
        if (i % 0x10000 == 0)
            printf("progress: %d%%\n", i * 100 / SIZE);
    }

    printf("2 byte read/write test\n");
    for (int i = 0; i < SIZE; i += 0x2) {
        volatile short *addr = (short *)(PSRAM_START + i);
        *addr = i;
        check(*addr == (short)i);
        if (i % 0x10000 == 0)
            printf("progress: %d%%\n", i * 100 / SIZE);
    }

    printf("2 byte read test\n");
    for (int i = 0; i < SIZE; i += 0x2) {
        volatile short *addr = (short *)(PSRAM_START + i);
        check(*addr == (short)i);
        if (i % 0x10000 == 0)
            printf("progress: %d%%\n", i * 100 / SIZE);
    }

    printf("4 byte read/write test\n");
    for (int i = 0; i < SIZE; i += 0x4) {
        volatile int *addr = (int *)(PSRAM_START + i);
        *addr = i;
        check(*addr == (int)i);
        if (i % 0x10000 == 0)
            printf("progress: %d%%\n", i * 100 / SIZE);
    }

    printf("4 byte read test\n");
    for (int i = 0; i < SIZE; i += 0x4) {
        volatile int *addr = (int *)(PSRAM_START + i);
        check(*addr == (int)i);
        if (i % 0x10000 == 0)
            printf("progress: %d%%\n", i * 100 / SIZE);
    }

    return 0;
}
