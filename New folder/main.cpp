/*
 * MAX7221project.cpp
 *
 * Created: 3/27/2019 9:25:42 AM
 * Author : Mateusz Trójca
 */ 

#include <util/delay.h>
#include "driver.h"

#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000
#endif

int main(void) 
{

	MAX7219 display(0, 1, 2);
	display.scanlimit(4);
	display.sendCommand(0x01, 0x01);
	display.sendCommand(0x02, 0x02);
	display.sendCommand(0x03, 0x03);
	display.sendCommand(0x04, 0x04);
	display.sendCommand(0x05, 0x05);
	display.sendCommand(0x0C, 0x01);  // normal mode
	display.sendCommand(0x09, 0xFF);  // code B decode

	uint8_t i=0;
	while(1) {
		
		display.sendCommand(0x01, i);
		i++;
		if (i>9)
			i=0;
		_delay_ms(1000);
	}
}