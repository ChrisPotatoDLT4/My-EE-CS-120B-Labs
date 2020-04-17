
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
        DDRD = 0x00; //0000 0000
	PORTD = 0xFF;

	DDRB = 0xFE; //1111 1110
	PORTB = 0x01;
	//OUTPUTS
	
	unsigned char weightNum = 0x00;
	unsigned char weightTwo = 0x00;
	unsigned short totalWeight = 0x00; //char is 8 bits, short is 9

while(1){
	weightNum = PIND;
	weightTwo = PINB & 0x01;

	totalWeight = weightNum + weightTwo;

	if( totalWeight >= 70 ){
		PORTB = 0x02;
	}
	else if( ((totalWeight > 5) && (totalWeight < 70)) ){
		PORTB = 0x04;

	}
	else {PORTB = 0x00;}
	 
	        
}

return 1;
}

