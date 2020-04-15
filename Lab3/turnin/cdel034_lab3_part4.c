
/* Author:cdel034
 * **  Partner(s) Name:
 * **      Lab Section:
 * **      Assignment: Lab #  Exercise #
 * **      Exercise Description: [optional - include for your own benefit]
 * **
 * **      I acknowledge all content contained herein, excluding template or example
 * **      code, is my own original work.
 * **/
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
int main(void){

	//INPUTS
        DDRA = 0x00;
	PORTA = 0xFF;
	//OUTPUTS
	DDRB = 0x0F;
	PORTB = 0xF0;

	DDRC = 0xF0;
	PORTC = 0x0F;

	unsigned char bitValue = 0x00;
	
while(1){

	bitValue = PINA;

	PORTB = (bitValue & 0xF0) >>4;//lowerNibble 0000 1111
	PORTC = (bitValue & 0x0F) <<4;//upperNibble 1111 0000

        
}

return 1;
}

