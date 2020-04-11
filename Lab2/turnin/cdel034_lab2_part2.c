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

	DDRA = 0xF0;    //Configure port A's 1111 0000 pins 0-3 as inputs
        PORTA = 0x0F;   //Haveing this to be output pins
// 1 means a car is parked in the space of a 4 space parking lot


	DDRC = 0xFF;
	PORTC = 0x00;

	unsigned char firstSpace = 0x00;
	unsigned char secondSpace = 0x00;
	unsigned char thirdSpace = 0x00;
	unsigned char fourthSpace = 0x00;

	unsigned char varOne = 0x00;
	unsigned char varTwo = 0x00;
	unsigned char varThree = 0x00;
	unsigned char varFour = 0x00;	

        unsigned char cntavail = 0x00;

//	cntavail = 0x00;
        while(1){
        firstSpace = PINA & 0x01; //A0 0001
        secondSpace = PINA & 0x02;//A1 0010
        thirdSpace = PINA & 0x04; //A2 0100
        fourthSpace = PINA & 0x08;//A3 1000

		if (firstSpace == 0x01){
		  varOne = 0x01;
		}
		else {varOne = 0x00;}

		if (secondSpace == 0x02){
		   varTwo = 0x01;
		}
		else{varTwo = 0x00;}

		if(thirdSpace ==0x04){
		   varThree = 0x01;
		}
		else{varThree = 0x00;}
	
		if(fourthSpace ==0x08){
		  varFour = 0x01;
		}
		else{varFour = 0x00;}
	//	else {cntavail = 0x00;}
             cntavail = varOne + varTwo + varThree + varFour;
	   PORTC = 0x04 -  cntavail;
        }


    return 1;
}

