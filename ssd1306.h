#ifndef SSD1306_H_
#define SSD1306_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_COMMAND_BYTE 0x80
#define SSD1306_DATA_BYTE 0x40

#define SSD1306_COMMAND_LEVEL 0
#define SSD1306_DATA_LEVEL 1

typedef uint8_t SSD1306_Interface_t;
typedef uint8_t SSD1306_Command_t;
typedef uint8_t I2C_Address;

typedef void (*SPI_Transmit)(uint8_t* data, size_t size);
typedef void (*SPI_ChipSelect)(uint8_t level);
typedef void (*SelectDataCommand)(uint8_t level);
typedef void (*I2C_Transmit)(uint8_t address, uint8_t* data, size_t size);

typedef struct{
	SPI_Transmit spiTransmit;
	SPI_ChipSelect spiChipSelect;
	SelectDataCommand selectDataCommand;
	I2C_Transmit i2cTransmit;
	I2C_Address i2cAddress;
	SSD1306_Interface_t interface;
}SSD1306_st;

enum SSD1306_Interface_e{
	INTERFACE_I2C,
	INTERFACE_SPI
};

enum SSD1306_OneByteCommand_e{
	SET_DISPLAY_START_LINE = 0x40,
	SET_SEGMENT_REMAP = 0xA0,
	SET_COM_OUTPUT_SCAN_DIRECTION = 0xC0,
	DISABLE_ENTIRE_DISPLAY_ON = 0xA4,
	SET_NORMAL_DISPLAY = 0xA6,
	SET_DISPLAY_ON = 0xAF,
	SET_DISPLAY_OFF = 0xAE
};

enum SSD1306_TwoByteCommand_e{
	SET_MULTIPLEX_RATIO = 0xA8,
	SET_DISPLAY_OFFSET = 0xD3,
	SET_COM_PINS_HARDWARE_CONFIGURATION = 0xDA,
	SET_CONTRAST_CONTROL = 0x81,
	SET_OSC_FREQUENCY = 0xD5,
	ENABLE_CHARGE_PUMP_REGULATION = 0x8D,
	SET_MEMORY_ADDRESSING_MODE = 0x20
};

enum SSD1306_ThreeByteCommand_e{
	SET_COLUMN_ADDRESS = 0x21,
	SET_PAGE_ADDRESS = 0x22,
};

#ifdef __cplusplus
extern "C" {
#endif

void SSD1306_Init(SSD1306_st* ssd1306, SSD1306_Interface_t interface,
		SPI_Transmit spiTransmit, SPI_ChipSelect spiChipSelect, SelectDataCommand selectDataCommand,
		I2C_Transmit i2cTransmit, I2C_Address i2cAddress);
void SSD1306_SendOneByteCommand(SSD1306_st* ssd1306, SSD1306_Command_t command);
void SSD1306_SendTwoByteCommand(SSD1306_st* ssd1306, SSD1306_Command_t command, uint8_t value);
void SSD1306_SendThreeByteCommand(SSD1306_st* ssd1306, SSD1306_Command_t command, uint8_t value1, uint8_t value2);
void SSD1306_SendCommand(SSD1306_st* ssd1306, SSD1306_Command_t command);
void SSD1306_SendData(SSD1306_st* ssd1306, uint8_t* data, size_t size);

#ifdef __cplusplus
}
#endif

#endif
