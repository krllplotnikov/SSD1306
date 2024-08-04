#include "OLED_SSD1306.h"

void OLED_SSD1306_Init(OLED_SSD1306_st* oled_ssd1306, SSD1306_Interface_t interface,
		SPI_Transmit spiTransmit, SPI_ChipSelect spiChipSelect, SPI_DataCommand spiDataCommand,
		I2C_Transmit i2cTransmit, I2C_Address i2cAddress){
	SSD1306_Init(&oled_ssd1306->ssd1306, interface, spiTransmit, spiChipSelect, spiDataCommand, i2cTransmit, i2cAddress);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, SET_MULTIPLEX_RATIO, 0x3F);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, SET_DISPLAY_OFFSET, 0x00);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_DISPLAY_START_LINE);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_SEGMENT_REMAP + 0x01);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_COM_OUTPUT_SCAN_DIRECTION + 0x08);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, SET_COM_PINS_HARDWARE_CONFIGURATION, 0x12);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, SET_CONTRAST_CONTROL, 0x7F);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, DISABLE_ENTIRE_DISPLAY_ON);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_NORMAL_DISPLAY);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, SET_OSC_FREQUENCY, 0x80);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, ENABLE_CHARGE_PUMP_REGULATION, 0x14);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_DISPLAY_ON);
	SSD1306_SendTwoByteCommand(&oled_ssd1306->ssd1306, SET_MEMORY_ADDRESSING_MODE, 0x00);

	memset(oled_ssd1306->displayBuffer, 0x00, DISPLAY_BUFFER_SIZE);

	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_COLUMN_ADDRESS);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, 0x00);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SSD1306_WIDTH - 1);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SET_PAGE_ADDRESS);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, 0x00);
	SSD1306_SendOneByteCommand(&oled_ssd1306->ssd1306, SSD1306_HEIGHT / 8 - 1);
	SSD1306_SendData(&oled_ssd1306->ssd1306, oled_ssd1306->displayBuffer, DISPLAY_BUFFER_SIZE);
}

void OLED_SSD1306_SetPixel(OLED_SSD1306_st* oled_ssd1306, uint8_t x, uint8_t y, uint8_t state){
	switch (state)
	{
		case PIXEL_STATE_ON:  oled_ssd1306->displayBuffer[x + (y/8)*SSD1306_WIDTH] |=  (1 << (y&7)); break;
		case PIXEL_STATE_OFF:  oled_ssd1306->displayBuffer[x + (y/8)*SSD1306_WIDTH] &= ~(1 << (y&7)); break;
	}
}

void OLED_SSD1306_DrawDisplay(OLED_SSD1306_st* oled_ssd1306){
	SSD1306_SendThreeByteCommand(&oled_ssd1306->ssd1306, SET_COLUMN_ADDRESS, 0x00, SSD1306_WIDTH - 1);
	SSD1306_SendThreeByteCommand(&oled_ssd1306->ssd1306, SET_PAGE_ADDRESS, 0x00, SSD1306_HEIGHT / 8 - 1);
	SSD1306_SendData(&oled_ssd1306->ssd1306, oled_ssd1306->displayBuffer, DISPLAY_BUFFER_SIZE);
}
