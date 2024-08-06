#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "ssd1306.h"

#define PIXEL_STATE_OFF 0
#define PIXEL_STATE_ON 1

#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH  128

#define DISPLAY_BUFFER_SIZE DISPLAY_HEIGHT * DISPLAY_WIDTH / 8

typedef struct{
	uint8_t positionX; //0 - 127
	uint8_t positionY; //0 - 7
}TextCursor_st;

typedef struct{
	SSD1306_st ssd1306;
	TextCursor_st cursor;
	uint8_t displayBuffer[DISPLAY_BUFFER_SIZE];
}Display_st;

void Display_Init(Display_st* display, SSD1306_Interface_t interface,
		SPI_Transmit spiTransmit, SPI_ChipSelect spiChipSelect,  SelectDataCommand selectDataCommand,
		I2C_Transmit i2cTransmit, I2C_Address i2cAddress);
void Display_SetPixel(Display_st* display, uint8_t x, uint8_t y, uint8_t state);
void Display_SetPage(Display_st* display, uint8_t row, uint8_t column, uint8_t data);
void Display_InvertPage(Display_st* display, uint8_t row, uint8_t column);
void Display_SetTextCursor(Display_st* display, uint8_t row, uint8_t column);
void Display_PrintText(Display_st* display, char* text);
void Display_Clear(Display_st* display);
void Display_Refresh(Display_st* display);

TextCursor_st Display_GetTextCursor(Display_st* display);

#endif
