#include "klibtest.h"

// test strcpy

#define N 27

char str[N][64] = {
    "",
    "a",
    "ab",
    "abc",
    "abcd",
    "abcde",
    "abcdef",
    "abcdefg",
    "abcdefgh",
    "abcdefghi",
    "abcdefghij",
    "abcdefghijk",
    "abcdefghijkl",
    "abcdefghijklm",
    "abcdefghijklmn",
    "abcdefghijklmno",
    "abcdefghijklmnop",
    "abcdefghijklmnopq",
    "abcdefghijklmnopqr",
    "abcdefghijklmnopqrs",
    "abcdefghijklmnopqrst",
    "abcdefghijklmnopqrstu",
    "abcdefghijklmnopqrstuv",
    "abcdefghijklmnopqrstuvw",
    "abcdefghijklmnopqrstuvwx",
    "abcdefghijklmnopqrstuvwxy",
    "abcdefghijklmnopqrstuvwxyz",
};

#define DATA_SIZE 1000

static uint8_t data[DATA_SIZE];

int main() {
    for (int test = 0; test < N; test++) {
        init_seq(data, DATA_SIZE);
        char *s = str[test];
        char *d = (char *)data;

        char *ret = strcpy(d + test, s);
        check(ret == d + test);
        check_seq((uint8_t *)d, 0, test);
        for (int i = test; i < test + test; i++) {
            check(d[i] == s[i - test]);
        }
        check(d[test + test] == '\0');
        check(d[test + test + 1] == test + test + 1);
        check_seq((uint8_t *)d, test + test + 1, DATA_SIZE);
    }
    return 0;
}
