#include "trap.h"

int main() {
    volatile uint32_t *clint_timerh = (uint32_t *)0x0200bffc;
    volatile uint32_t *clint_timerl = (uint32_t *)0x0200bff8;
    volatile uint32_t *clint_timermatchh = (uint32_t *)0x02004004;
    volatile uint32_t *clint_timermatchl = (uint32_t *)0x02004000;
    *clint_timermatchh = 0x0;
    *clint_timermatchl = 0x10000;

    for (int i = 0; i < 100; i++) {
        printf("clint_timerh: 0x%x, clint_timerl: 0x%x\n", *clint_timerh, *clint_timerl);
        printf("clint_timermatchh: 0x%x, clint_timermatchl: 0x%x\n", *clint_timermatchh, *clint_timermatchl);
    }

    return 0;
}
