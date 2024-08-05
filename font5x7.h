#ifndef FONT5X7_H_
#define FONT5X7_H_

#include "stdio.h"

#define SYMBOL_5X7_MAX_WIDTH 5

typedef struct{
	uint8_t symbolWidth;
	uint8_t symbolHeight;
	uint8_t symbolData[SYMBOL_5X7_MAX_WIDTH];
}Symbol_5x7_st;

#endif
