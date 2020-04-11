/*Author: cdel034
 **  Partner(s) Name:
 **      Lab Section:
 **      Assignment: Lab #  Exercise #
 **      Exercise Description: [optional - include for your own benefit]
 **
 **      I acknowledge all content contained herein, excluding template or example
 **      code, is my own original work.
 **/
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

	DDRA = 0x00;
        PORTA = 0xFF;
   
	DDRB = 0x00;
	PORTB =0xFF;	

	DDRC = 0x00;
	PORTC = 0xFF;

	DDRD = 0xFF;
	PORTD = 0x00;

	unsigned char totalWeight = 0x00; //output
	unsigned char seatOne = 0x00; //A
	unsigned char seatTwo = 0x00; //B
	unsigned char seatThree = 0x00; //C

	unsigned char outputOne = 0x00;
	unsigned char outputTwo = 0x00;

        while(1){

		seatOne = PINA ;
		seatTwo = PINB ;
		seatThree = PINC;
      		totalWeight = seatOne + seatTwo +seatThree;

		if(totalWeight > 140 ){
		outputOne = 0x01;
	}
	
		else{outputOne = 0x00;}

		if( (seatOne - seatThree) > 80 || ((seatThree - seatOne) >80)  ){
		outputTwo = 0x02;
	}
		else {outputTwo = 0x00 ;}

		totalWeight = 0xFC & totalWeight ;
		PORTD = totalWeight + outputOne + outputTwo;

	}

    return 1;
}

