#include "trap.h"

const char *str = "Hello, World!\n";

int main() {
    // virtual out
    for (const char *ch = str; *ch != '\0'; ch++) {
        asm volatile("csrw 0x139, %0" : : "r"(*ch));
    }

    // virtual in
    while (1) {
        int ch;
        asm volatile("csrr %0, 0x140" : "=r"(ch));
        if ((ch & 0xff) != 0xff) {
            asm volatile("csrw 0x139, %0" : : "r"(ch & 0xff));
        }
    }

    return 0;
}
