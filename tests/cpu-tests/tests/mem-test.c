#include "trap.h"
#define MAX_BYTES 1

#define HEAP_START (0x0f000000 + 0x1000)
#define HEAP_SIZE 0x1000

int main() {
    // 8-bits
    uint8_t *heap = (uint8_t *)HEAP_START;
    for (int i = 0; i < HEAP_SIZE; i += sizeof(uint8_t)) {
        heap[i] = (uint8_t)(HEAP_START + i);
    }
    for (int i = 0; i < HEAP_SIZE; i += sizeof(uint8_t)) {
        check(heap[i] == (uint8_t)(HEAP_START + i));
    }

    // 16-bits
    for (int i = 0; i < HEAP_SIZE; i += sizeof(uint16_t)) {
        *(uint16_t *)(heap + i) = (uint16_t)(HEAP_START + i);
    }
    for (int i = 0; i < HEAP_SIZE; i += sizeof(uint16_t)) {
        check(*(uint16_t *)(heap + i) == (uint16_t)(HEAP_START + i));
    }

    // 32-bits
    for (int i = 0; i < HEAP_SIZE; i += sizeof(uint32_t)) {
        *(uint32_t *)(heap + i) = (uint32_t)(HEAP_START + i);
    }
    for (int i = 0; i < HEAP_SIZE; i += sizeof(uint32_t)) {
        check(*(uint32_t *)(heap + i) == (uint32_t)(HEAP_START + i));
    }

    return 0;
}
