#include "ssd1306.h"

void SSD1306_Init(SSD1306_st* ssd1306, SSD1306_Interface_t interface,
		SPI_Transmit spiTransmit, SPI_ChipSelect spiChipSelect, SPI_DataCommand spiDataCommand,
		I2C_Transmit i2cTransmit, I2C_Address i2cAddress){
	ssd1306->interface = interface;
	ssd1306->spiTransmit = spiTransmit;
	ssd1306->spiChipSelect = spiChipSelect;
	ssd1306->spiDataCommand = spiDataCommand;
	ssd1306->i2cTransmit = i2cTransmit;
	ssd1306->i2cAddress = i2cAddress;
}

void SSD1306_SendCommand(SSD1306_st* ssd1306, SSD1306_Command_t command){
	if(ssd1306->interface == INTERFACE_I2C){
		uint8_t commandBuffer[2] = {SSD1306_COMMAND_BYTE, command};
		ssd1306->i2cTransmit(ssd1306->i2cAddress, commandBuffer, 2);
	}
	else if(ssd1306->interface == INTERFACE_SPI){
		if(ssd1306->spiChipSelect != NULL) ssd1306->spiChipSelect(0);
		ssd1306->spiDataCommand(SSD1306_COMMAND_LEVEL);
		ssd1306->spiTransmit(&command, 1);	
		ssd1306->spiDataCommand(SSD1306_DATA_LEVEL);
		if(ssd1306->spiChipSelect != NULL) ssd1306->spiChipSelect(1);
	}
}

void SSD1306_SendOneByteCommand(SSD1306_st* ssd1306, SSD1306_Command_t command){
	SSD1306_SendCommand(ssd1306, command);
}

void SSD1306_SendTwoByteCommand(SSD1306_st* ssd1306, SSD1306_Command_t command, uint8_t value){
	SSD1306_SendCommand(ssd1306, command);
	SSD1306_SendCommand(ssd1306, value);
}

void SSD1306_SendThreeByteCommand(SSD1306_st* ssd1306, SSD1306_Command_t command, uint8_t value1, uint8_t value2){
	SSD1306_SendCommand(ssd1306, command);
	SSD1306_SendCommand(ssd1306, value1);
	SSD1306_SendCommand(ssd1306, value2);
}

void SSD1306_SendData(SSD1306_st* ssd1306, uint8_t* data, size_t size){
	if(ssd1306->interface == INTERFACE_I2C){
		uint8_t dataBuffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8 + 1] = {SSD1306_DATA_BYTE};
		memcpy(dataBuffer + 1, data, size);
		ssd1306->i2cTransmit(ssd1306->i2cAddress, dataBuffer, size + 1);
	}
	else if(ssd1306->interface == INTERFACE_SPI){
		if(ssd1306->spiChipSelect != NULL) ssd1306->spiChipSelect(0);
		ssd1306->spiDataCommand(SSD1306_DATA_LEVEL);
		ssd1306->spiTransmit(data, size);
		if(ssd1306->spiChipSelect != NULL) ssd1306->spiChipSelect(1);
	}
}
