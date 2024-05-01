#include "trap.h"

int main() {

    // csrrw
    asm volatile("li t1, 0x1234");
    asm volatile("csrrw t0, mstatus, t1");
    asm volatile("li t1, 0x0");
    int t1;
    asm volatile("csrrw %0, mstatus, x0" : "=r"(t1));
    check(t1 == 0x1234);

    asm volatile("csrrs t0, mstatus, t1");
    asm volatile("csrrc t0, mstatus, t1");

    // csrrwi
    asm volatile("csrrwi t0, mstatus, 0xa");
    asm volatile("csrrwi %0, mstatus, 0x0" : "=r"(t1));
    check(t1 == 0xa);

    // csrrsi
    asm volatile("csrrsi t0, mstatus, 0x1");
    asm volatile("csrrsi %0, mstatus, 0x0" : "=r"(t1));
    check(t1 == 0x1);

    // csrrci
    asm volatile("csrrsi t0, mstatus, 0x1");
    asm volatile("csrrci t0, mstatus, 0x1");
    asm volatile("csrrci %0, mstatus, 0x0" : "=r"(t1));
    check(t1 == 0x0);

    return 0;
}
