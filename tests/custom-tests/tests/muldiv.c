#include "trap.h"

int main() {
    uint32_t a, b, c;


    // test mul
    a = 0x12345678;
    b = 0x87654321;
    asm volatile("mul %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0x70b88d78);

    // test mulh
    a = 0x12345678;
    b = 0x87654321;
    asm volatile("mulh %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0xf76c768d);

    // test mulhsu
    a = 0x12345678;
    b = 0x87654321;
    asm volatile("mulhsu %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0x9a0cd05);

    a = 0x87654321;
    b = 0x12345678;
    asm volatile("mulhsu %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0xf76c768d);

    // test mulhu
    a = 0x12345678;
    b = 0x87654321;
    asm volatile("mulhu %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0x9a0cd05);

    // test div
    a = 0x12345678;
    b = 0xffff0000;
    asm volatile("div %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0xffffedcc);

    // test divu
    a = 0x12345678;
    b = 0xffff0000;
    asm volatile("divu %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0x0);

    // test rem
    a = 0x12345678;
    b = 0xffff0000;
    asm volatile("rem %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0x5678);

    // test remu
    a = 0x12345678;
    b = 0xffff0000;
    asm volatile("remu %0, %1, %2" : "=r"(c) : "r"(a), "r"(b));
    check(c == 0x12345678);



    return 0;
}
