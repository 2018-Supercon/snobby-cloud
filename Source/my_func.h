#ifndef	__MY_FUNC_H
#define	__MY_FUNC_H
#include "hw.h"
#include "disp.h"
#include "badge.h"

#define FILES 10

struct file{
	uint8_t name[16];
	uint8_t data[256];
}filesys[FILES];

void call_command(uint8_t char_buff[], struct file filesys[FILES]);
void animate_splash(void);
void screen_splash(uint32_t color);
// command funcs:
void touch(uint8_t char_buff[], uint8_t i, struct file filesys[FILES]);
void ls(struct file filesys[FILES]);
void rm(uint8_t char_buff[], uint8_t i, struct file filesys[FILES]);
void write(struct file filesys[FILES], uint8_t index);
uint8_t find(uint8_t char_buff[256], uint8_t i, struct file filesys[FILES]);
void cat(struct file filesys[FILES], uint8_t index);
void help(void);














#endif