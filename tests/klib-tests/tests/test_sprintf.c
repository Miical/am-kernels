#include "klibtest.h"

#define N 64

char data[N];

int main() {
    init_seq((uint8_t*)data, N);
    sprintf(data, "num: %d", 123);

    check(strcmp(data, "num: 123") == 0);
    check_seq((uint8_t*)data, 9, N);

    init_seq((uint8_t*)data, N);
    sprintf(data, "string: %s", "hello world!");
    check(strcmp(data, "string: hello world!") == 0);
    check_seq((uint8_t*)data, 21, N);
    return 0;
}
