#include "Display.h"
#include "microFont.h"
#include <string.h>

extern MicroSymbol_st microSymbols[255];

void Display_Init(Display_st* display, SSD1306_Interface_t interface,
		SPI_Transmit spiTransmit, SPI_ChipSelect spiChipSelect, SelectDataCommand selectDataCommand,
		I2C_Transmit i2cTransmit, I2C_Address i2cAddress){
	SSD1306_Init(&display->ssd1306, interface, spiTransmit, spiChipSelect, selectDataCommand, i2cTransmit, i2cAddress);
	SSD1306_SendTwoByteCommand(&display->ssd1306, SET_MULTIPLEX_RATIO, 0x3F);
	SSD1306_SendTwoByteCommand(&display->ssd1306, SET_DISPLAY_OFFSET, 0x00);
	SSD1306_SendOneByteCommand(&display->ssd1306, SET_DISPLAY_START_LINE);
	SSD1306_SendOneByteCommand(&display->ssd1306, SET_SEGMENT_REMAP + 0x01);
	SSD1306_SendOneByteCommand(&display->ssd1306, SET_COM_OUTPUT_SCAN_DIRECTION + 0x08);
	SSD1306_SendTwoByteCommand(&display->ssd1306, SET_COM_PINS_HARDWARE_CONFIGURATION, 0x12);
	SSD1306_SendTwoByteCommand(&display->ssd1306, SET_CONTRAST_CONTROL, 0x7F);
	SSD1306_SendOneByteCommand(&display->ssd1306, DISABLE_ENTIRE_DISPLAY_ON);
	SSD1306_SendOneByteCommand(&display->ssd1306, SET_NORMAL_DISPLAY);
	SSD1306_SendTwoByteCommand(&display->ssd1306, SET_OSC_FREQUENCY, 0x80);
	SSD1306_SendTwoByteCommand(&display->ssd1306, ENABLE_CHARGE_PUMP_REGULATION, 0x14);
	SSD1306_SendOneByteCommand(&display->ssd1306, SET_DISPLAY_ON);
	SSD1306_SendTwoByteCommand(&display->ssd1306, SET_MEMORY_ADDRESSING_MODE, 0x00);

	memset(display->displayBuffer, 0x00, DISPLAY_BUFFER_SIZE);

	SSD1306_SendOneByteCommand(&display->ssd1306, SET_COLUMN_ADDRESS);
	SSD1306_SendOneByteCommand(&display->ssd1306, 0x00);
	SSD1306_SendOneByteCommand(&display->ssd1306, DISPLAY_WIDTH - 1);
	SSD1306_SendOneByteCommand(&display->ssd1306, SET_PAGE_ADDRESS);
	SSD1306_SendOneByteCommand(&display->ssd1306, 0x00);
	SSD1306_SendOneByteCommand(&display->ssd1306, DISPLAY_HEIGHT / 8 - 1);
	SSD1306_SendData(&display->ssd1306, display->displayBuffer, DISPLAY_BUFFER_SIZE);
}

void Display_SetPixel(Display_st* display, uint8_t x, uint8_t y, uint8_t state){
	switch (state)
	{
		case PIXEL_STATE_ON:  display->displayBuffer[x + (y/8)* DISPLAY_WIDTH] |=  (1 << (y&7)); break;
		case PIXEL_STATE_OFF: display->displayBuffer[x + (y/8)* DISPLAY_WIDTH] &= ~(1 << (y&7)); break;
	}
}

void Display_SetPage(Display_st* display, uint8_t row, uint8_t column, uint8_t data){
	display->displayBuffer[column + row * DISPLAY_WIDTH] = data;
}

void Display_SetTextCursor(Display_st* display, uint8_t row, uint8_t column){
	display->cursor.positionX = column;
	display->cursor.positionY = row;
}

void Display_PrintText(Display_st* display, char* text){
	size_t textLength = strlen(text);
	for(size_t i = 0; i < textLength; i++){
		Display_SetPage(display, display->cursor.positionY, display->cursor.positionX, 0x00);
		display->cursor.positionX++;
		for(uint8_t j = 0; j < microSymbols[(uint8_t)*(text + i)].symbolWidth; j++){
			Display_SetPage(display, display->cursor.positionY, display->cursor.positionX, microSymbols[(uint8_t)*(text + i)].symbolData[j]);
			display->cursor.positionX++;
		}
	}
	display->cursor.positionX--;
}

void Display_DrawBitmap(Display_st* display, uint8_t* bitmap, uint8_t height, uint8_t width, uint8_t startX, uint8_t startY){
	for(uint8_t y = 0; y < height; y++){
		for(uint8_t x = 0; x < width; x++){
			uint8_t pixelState = bitmap[x + (y / 8) * width] & (1 << y) ? PIXEL_STATE_ON : PIXEL_STATE_OFF;
			Display_SetPixel(display, startX + x, startY + y, pixelState);
		}
	}

}

void Display_Clear(Display_st* display){
	memset(display->displayBuffer, 0, DISPLAY_BUFFER_SIZE);
}

void Display_InvertPage(Display_st* display, uint8_t row, uint8_t column){
	display->displayBuffer[column + row * DISPLAY_WIDTH] = ~(display->displayBuffer[column + row * DISPLAY_WIDTH]);
}

void Display_Refresh(Display_st* display){
	SSD1306_SendThreeByteCommand(&display->ssd1306, SET_COLUMN_ADDRESS, 0x00, DISPLAY_WIDTH - 1);
	SSD1306_SendThreeByteCommand(&display->ssd1306, SET_PAGE_ADDRESS, 0x00, DISPLAY_HEIGHT / 8 - 1);
	SSD1306_SendData(&display->ssd1306, display->displayBuffer, DISPLAY_BUFFER_SIZE);
}
