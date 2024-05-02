#include "trap.h"

int main() {
    uint32_t a, b, addr;

    // amoswap.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    a = 0x5678;
    asm volatile("amoswap.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x1234);
    check(*(volatile uint32_t *)addr == 0x5678);

    // amoadd.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    a = 0x5678;
    asm volatile("amoadd.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x1234);
    check(*(volatile uint32_t *)addr == 0x1234 + 0x5678);

    // amoxor.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    a = 0x5678;
    asm volatile("amoxor.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x1234);
    check(*(volatile uint32_t *)addr == (0x1234 ^ 0x5678));

    // amoand.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    a = 0x5678;
    asm volatile("amoand.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x1234);
    check(*(volatile uint32_t *)addr == (0x1234 & 0x5678));

    // amoor.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    a = 0x5678;
    asm volatile("amoor.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x1234);
    check(*(volatile uint32_t *)addr == (0x1234 | 0x5678));

    // amomin.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x12345678), "r"(addr));
    a = 0x87654321;
    asm volatile("amomin.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x12345678);
    check(*(volatile uint32_t *)addr == 0x87654321);

    // amomax.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x12345678), "r"(addr));
    a = 0x87654321;
    asm volatile("amomax.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x12345678);
    check(*(volatile uint32_t *)addr == 0x12345678);

    // amominu.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x12345678), "r"(addr));
    a = 0x87654321;
    asm volatile("amominu.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x12345678);
    check(*(volatile uint32_t *)addr == 0x12345678);

    // amomaxu.w
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x12345678), "r"(addr));
    a = 0x87654321;
    asm volatile("amomaxu.w %0, %1, 0(%2)" : "=r"(b) : "r"(a), "r"(addr));
    check(b == 0x12345678);
    check(*(volatile uint32_t *)addr == 0x87654321);

    // lr.w and sc.w
    // test 1
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    asm volatile("lr.w %0, 0(%1)" : "=r"(a) : "r"(addr));
    check(a == 0x1234);
    asm volatile("sc.w %0, %1, 0(%2)" : "=r"(b) : "r"(0x5678), "r"(addr));
    check(b == 0);
    check(*(volatile uint32_t *)addr == 0x5678);

    // test 2
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    asm volatile("lr.w %0, 0(%1)" : "=r"(a) : "r"(addr));
    check(a == 0x1234);
    asm volatile("sw %0, 0(%1)" : : "r"(0x5678), "r"(addr));
    asm volatile("sc.w %0, %1, 0(%2)" : "=r"(b) : "r"(0x9abc), "r"(addr));
    check(b == 1);
    check(*(volatile uint32_t *)addr == 0x5678);

    // test 3
    addr = 0x80100000;
    asm volatile("sw %0, 0(%1)" : : "r"(0x1234), "r"(addr));
    asm volatile("lr.w %0, 0(%1)" : "=r"(a) : "r"(addr));
    check(a == 0x1234);
    asm volatile("sw %0, 0(%1)" : : "r"(0x5678), "r"(addr + 4));
    asm volatile("sc.w %0, %1, 0(%2)" : "=r"(b) : "r"(0x9abc), "r"(addr));
    check(b == 0);
    check(*(volatile uint32_t *)addr == 0x9abc);

    return 0;
}
