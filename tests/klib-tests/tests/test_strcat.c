#include "klibtest.h"

#define N 64

char data[N];

int main() {
    init_seq((uint8_t*)data, N);
    data[0] = '\0';
    check(strcat(data, "hello world!") == data);

    check(strcmp(data, "hello world!") == 0);
    check_seq((uint8_t*)data, 13, N);

    return 0;
}
