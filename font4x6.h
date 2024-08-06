#ifndef FONT4X6_H_
#define FONT4X6_H_

#include "stdio.h"

#define SYMBOL_4X6_MAX_WIDTH 6

typedef struct{
	uint8_t symbolWidth;
	uint8_t symbolHeight;
	uint8_t symbolData[SYMBOL_4X6_MAX_WIDTH];
}Symbol_4x6_st;

#endif
