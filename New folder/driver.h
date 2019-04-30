#ifndef DRIVER_H_
#define DRIVER_H_

#include <avr/io.h>

class MAX7219 {
	public:
	MAX7219(uint8_t pin_din, uint8_t pin_cs, uint8_t pin_clk);
	void initialize();
	void sendCommand(unsigned char address, unsigned char data);
	void MAX7219main(uint8_t a);
	private:
	void MAX7219main(uint8_t input);
	unsigned char portnumber;
	unsigned char input;
};

#endif /* DRIVER_H_ */