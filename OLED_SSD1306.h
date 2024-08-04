#ifndef OLED_SSD1306_H_
#define OLED_SSD1306_H_

#include "ssd1306.h"

#define PIXEL_STATE_OFF 0
#define PIXEL_STATE_ON 1

#define DISPLAY_BUFFER_SIZE SSD1306_WIDTH * SSD1306_HEIGHT / 8

typedef struct{
	SSD1306_st ssd1306;
	uint8_t displayBuffer[DISPLAY_BUFFER_SIZE];
}OLED_SSD1306_st;

void OLED_SSD1306_Init(OLED_SSD1306_st* oled_ssd1306, SSD1306_Interface_t interface,
		SPI_Transmit spiTransmit, SPI_ChipSelect spiChipSelect,  SPI_DataCommand spiDataCommand,
		I2C_Transmit i2cTransmit, I2C_Address i2cAddress);
void OLED_SSD1306_SetPixel(OLED_SSD1306_st* oled_ssd1306, uint8_t x, uint8_t y, uint8_t state);
void OLED_SSD1306_DrawDisplay(OLED_SSD1306_st* oled_ssd1306);

#endif
