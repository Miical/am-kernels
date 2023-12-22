#include "klibtest.h"

#define N 100
static uint8_t src[N];
static uint8_t dest[N];

void test_memcpy(size_t src_start, size_t dest_start, size_t length) {
    init_seq(src, N);
    init_seq(dest, N);

    check(memcpy(dest + dest_start, src + src_start, length) == dest + dest_start);

    check_seq(dest, 0, dest_start);
    check_seq(dest, dest_start + length, N);
    check(memcmp(dest + dest_start, src + src_start, length) == 0);
}

int main() {
    test_memcpy(0, 10, 20);
    test_memcpy(30, 50, 15);

    return 0;
}
