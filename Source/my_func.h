#ifndef	__MY_FUNC_H
#define	__MY_FUNC_H
#include "hw.h"
#include "disp.h"
#include "badge.h"

void call_command(uint8_t char_buff[]);
void animate_splash(void);
void screen_splash(uint32_t color);
void mkdir(uint8_t char_buff[], uint8_t i);

#endif