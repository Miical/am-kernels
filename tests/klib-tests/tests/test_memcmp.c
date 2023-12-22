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

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    check(memcmp("", "", 1) == 0);
    for (int i = 0; i < N; i++) {
        check(memcmp(str[i], str[i], i+1) == 0);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                check(memcmp(str[i], str[j], min(strlen(str[i]), strlen(str[j])) + 1)
                      == (i < j ? -('a' + i) : ('a' + j)));
            }
        }
    }
    return 0;
}
