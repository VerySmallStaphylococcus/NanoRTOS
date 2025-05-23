#pragma once

#ifndef TIMER_H
#define TIMER_H

// stdint.h 없이 직접 타입 정의
typedef unsigned int uint32_t;

void timer_init(void);
uint32_t get_system_time_ms(void);

#endif
