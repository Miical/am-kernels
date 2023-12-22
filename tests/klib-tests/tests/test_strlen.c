#include "klibtest.h"

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

int main() {
    for (int i = 0; i < N; i++) {
        check(strlen(str[i]) == i);
    }
    return 0;
}
