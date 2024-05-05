#include "trap.h"
#include <sys/types.h>

#define LINUX_IMAGE_IN_FLASH 0x30800000
#define DTB_IN_FLASH 0x30c00000

#define RAM_SIZE 0x6000000
#define LINUX_START 0x80000000
#define LINUX_IMAGE_SIZE 0x26A370

#define DTB_SIZE 0x600
#define DTB_START 0x85fff940

#define KERNEL_CMD_SIZE 13
#define KERNEL_CMD_START (DTB_START + 0xc0)
const char* kernel_command_line = "console=hvc0";

int main() {
    printf("[Linux Bootloader]\n");
    printf("Load Device Tree Blob...\n");

    for (uint32_t i = 0; i < DTB_SIZE; i += 4) {
        uint32_t* flash_addr = (uint32_t*)(DTB_IN_FLASH + i);
        uint32_t* ram_addr = (uint32_t*)(DTB_START + i);
        *ram_addr = *flash_addr;
    }

    for (uint32_t i = 0; i < KERNEL_CMD_SIZE; i++) {
        char* ram_addr = (char*)(KERNEL_CMD_START + i);
        *ram_addr = kernel_command_line[i];
    }

    printf("Device Tree Blob is loaded at 0x%x\n", DTB_START);

    printf("Load Linux Image...\n");

    uint32_t block = ((LINUX_IMAGE_SIZE / 100) & (~0x3)) + 4;
    for (uint32_t progress = 0; progress < 100; progress++) {
        uint32_t start = progress * block;
        uint32_t end = (progress + 1) * block;
        if (end > LINUX_IMAGE_SIZE) end = LINUX_IMAGE_SIZE;

        for (uint32_t i = start; i < end; i += 4) {
            uint32_t* flash_addr = (uint32_t*)(LINUX_IMAGE_IN_FLASH + i);
            uint32_t* ram_addr = (uint32_t*)(LINUX_START + i);
            *ram_addr = *flash_addr;
        }
        printf("Progress: %d%%\r", progress + 1);
    }

    printf("\nJump to Linux Image...\n");
    asm volatile("fence.i");

    asm volatile("mv a0, zero");
    asm volatile("li a1, %0" : : "i"(DTB_START));

    asm volatile("li ra, %0" : : "i"(LINUX_START));
    asm volatile("jr ra");

    return 0;
}
