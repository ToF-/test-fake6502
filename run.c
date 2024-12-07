
#include <stdio.h>
#include <stdint.h>
#include "fake6502.c"
#include "run_memory.h"


uint8_t ram[0x10000];

uint16_t origin = 0x0200;

void init_ram() {
    for(int i=0; i<0x10000; i++)
        ram[i] = 0;

    ram[0xFFFC] = 0x00;
    ram[0xFFFD] = 0x02;
    for(int i=0; i<BINARY_SIZE; i++) {
        ram[origin+i] = binary[i];
    }
}
void write6502(uint16_t address, uint8_t value) {
    ram[address] = value;
}

uint8_t read6502(uint16_t address) {
    return ram[address];
}

void hook() {
    printf("PC:   A  X  Y\n");
    printf("%04X %02X %02X %02X\n", pc, a, x, y);
}

int main() {
    hookexternal(*hook);
    init_ram();
    printf("reset…\n");
    reset6502();
    exec6502(100);
    printf("clockticks6502: %u\n", clockticks6502);
    return 0;
}

