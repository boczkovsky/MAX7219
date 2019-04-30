/*
 * MAX7221project.cpp
 *
 * Created: 3/27/2019 9:25:42 AM
 * Author : Mateusz Trójca
 */ 

#include <avr/io.h>
#include "driver.h"
/*!
Defining all of the ports that we are going to call later on, remember to change them if you are going to use different pins! 
*/
#define CS_HIGH() PORTB |= (1<<PB1)
#define CS_LOW() PORTB &= ~(1<<PB1)
#define CLK_HIGH() PORTB |= (1<<PB2)
#define CLK_LOW() PORTB &= ~(1<<PB2)
#define DATA_LOW() PORTB &= ~(1<<PB0)
#define DATA_HIGH() PORTB |= (1<<PB0)
#define PORT_INIT() DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2)

#define DIGITS 0x0B


/*!
Initialization of the MAX7219 to make it possible to send bits to it.
*/
MAX7219::MAX7219()
{
	PORT_INIT();
	CS_HIGH();
	initialize();
}

/*!
Function that changes the displayed number by counting to 9 and when the counter reaches 9 resets it to 0.
*/
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

/*!
Function that specifies to which address register and what data register send the bits.
*/
void MAX7219::sendCommand(unsigned char address, unsigned char data) {
	CS_LOW();
	MAX7219::MAX7219main(address);
	MAX7219::MAX7219main(data);
	CS_HIGH();
}

/*!
Initial setup of the MAX7219. From Shutdown mode to Test mode and from Test mode to the Decode mode.
*/
void MAX7219::initialize() {
	MAX7219::sendCommand(0x0C, 0x01); // Normal mode
	MAX7219::sendCommand(0x0F, 0x00); // Test mode
	MAX7219::sendCommand(0x09, 0xFF); // Decode mode
}

/*!
Setting up a scanning limit by using which you can define how many digits are being displayed. Scan rate is getting higher with fewer digits.
*/
void MAX7219::scanlimit(unsigned char digitcount) {
	MAX7219::sendCommand(DIGITS, digitcount);
}