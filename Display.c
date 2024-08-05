#include "Display.h"
#include "font5x7.h"
#include "font4x6.h"
#include <string.h>

extern Symbol_5x7_st symbols5x7[255];
extern Symbol_4x6_st symbols4x6[255];

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
		display->cursor.positionX++;
		for(uint8_t j = 0; j < symbols4x6[*(text + i) - 65].symbolWidth; j++){
			Display_SetPage(display, display->cursor.positionY, display->cursor.positionX, symbols4x6[*(text + i) - 65].symbolData[j]);
			display->cursor.positionX++;
		}
	}
	display->cursor.positionX--;
}

void Display_InvertPage(Display_st* display, uint8_t row, uint8_t column){
	display->displayBuffer[column + row * DISPLAY_WIDTH] = ~(display->displayBuffer[column + row * DISPLAY_WIDTH]);
}

void Display_Refresh(Display_st* display){
	SSD1306_SendThreeByteCommand(&display->ssd1306, SET_COLUMN_ADDRESS, 0x00, DISPLAY_WIDTH - 1);
	SSD1306_SendThreeByteCommand(&display->ssd1306, SET_PAGE_ADDRESS, 0x00, DISPLAY_HEIGHT / 8 - 1);
	SSD1306_SendData(&display->ssd1306, display->displayBuffer, DISPLAY_BUFFER_SIZE);
}
