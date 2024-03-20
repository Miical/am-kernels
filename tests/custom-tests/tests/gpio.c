#include "trap.h"
#define GPIO_START 0x10002000
#define LED_ADDR (GPIO_START + 0x00)
#define SWITCH_ADDR (GPIO_START + 0x04)
#define SEG7_ADDR (GPIO_START + 0x08)


uint16_t led_update() {
    static short led = 1;
    led = led << 1 | (led >> 15 & 1);
    return led;
}

int main() {
    volatile uint16_t *led = (uint16_t *)LED_ADDR;
    for (int i = 0; i < 48; i++) {
        *led = led_update();
        for (int j = 0; j < 1000; j++) {
            asm volatile("");
        }
    }

    volatile uint16_t *switchs = (uint16_t *)SWITCH_ADDR;
    uint16_t last_switchs = 0;
    while (1) {
        uint16_t current_switchs = *switchs;
        if (current_switchs != last_switchs) {
            printf("Switchs: %x\n", current_switchs);
            last_switchs = current_switchs;
        }
        if (current_switchs == 0x1) {
            *led = 0xffff;
            printf("Pass\n");
            break;
        }
    }

    volatile uint32_t *seg7 = (uint32_t *)SEG7_ADDR;
    *seg7 = 0x23060132;

    while (1);



    return 0;
}
