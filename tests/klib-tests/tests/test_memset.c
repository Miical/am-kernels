#include "klibtest.h"

#define N 100
static uint8_t data[N];

int main() {
    for (int l = 0; l < N; l++) {
        for (int r = l + 1; r <= N; r++) {
            init_seq(data, N);
            uint8_t val = (l + r) / 2;
            memset(data + l, val, r - l);
            check_seq(data, 0, l);
            check_eq(data, l, r, val);
            check_seq(data, r, N);
        }
    }
    return 0;
}
