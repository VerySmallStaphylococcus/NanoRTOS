//Raspberry Pi Pico 
#include "timer.h"

volatile uint32_t system_time_ms = 0;

void SysTick_Handler(void) {
    system_time_ms++;
}

void timer_init(void) {
    //setup RP2040 SysTick (125MHz)
    *((volatile unsigned int*)0xE000E014) = 125000 - 1; // Reload
    *((volatile unsigned int*)0xE000E018) = 0;           // Clear current
    *((volatile unsigned int*)0xE000E010) = 0x07;        // Enable, interrupt, processor clock
}

uint32_t get_system_time_ms(void) {
    return system_time_ms;
}
