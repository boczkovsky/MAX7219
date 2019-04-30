#include <avr/io.h>
#include "driver.h"

#define CS_HIGH() PORTB |= (1<<PB1)
#define CS_LOW() PORTB &= ~(1<<PB1)
#define CLK_HIGH() PORTB |= (1<<PB2)
#define CLK_LOW() PORTB &= ~(1<<PB2)
#define DATA_LOW() PORTB &= ~(1<<PB0)
#define DATA_HIGH() PORTB |= (1<<PB0)
#define PORT_INIT() DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2)

#define DIGITS 0X0B

// Lm7221::Lm7221(uint8_t pin_din, uint8_t pin_cs, uint8_t pin_clk)
MAX7219::MAX7219()
{
	PORT_INIT();
	CS_HIGH();
	initialize();
}


void MAX7219::initialize() {
	
}


void MAX7219::MAX7219main(uint8_t a)
{
	uint8_t i;
	for (i = 0; i< 8; i++, a <<= 1)
	{
		CLK_LOW();
		if (a & 0x80)
			DATA_HIGH();
		else
			DATA_LOW();
		CLK_HIGH();
	}
}

void MAX7219::sendCommand(unsigned char address, unsigned char data) {
	CS_LOW();
	MAX7219::MAX7219main(address);
	MAX7219::MAX7219main(data);
	CS_HIGH();
}

void MAX7219::initialize() {
	// Normal mode
	MAX7219::sendCommand(0x0C, 0x01);
	// Test mode into normal mode
	MAX7219::sendCommand(0x0F, 0x00);
	// Decode mode
	MAX7219::sendCommand(0x09, 0xFF);
}

void MAX7219::scanlimit(unsigned char digitcount) {
	MAX7219::sendCommand(DIGITS, digitcount);
}