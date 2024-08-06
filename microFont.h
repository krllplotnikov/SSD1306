#ifndef FONT4X6_H_
#define FONT4X6_H_

#include "stdio.h"

#define MICRO_SYMBOL_MAX_WIDTH 6

typedef struct{
	uint8_t symbolWidth;
	uint8_t symbolHeight;
	uint8_t symbolData[MICRO_SYMBOL_MAX_WIDTH];
}MicroSymbol_st;

#endif
