/*	Author: cdel034
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
//
//Count the number of 1s on ports A and B and output that number on port C. 
//
int main(void) {
    
	DDRA = 0x00; //Port A's pins all 8
	PORTA = 0xFF;

	DDRB = 0x00; //same thing as A, 8 pins to check
	PORTB = 0xFF;

	DDRC = 0xFF; //outputting how mnay ones we found
	PORTC = 0x00;

unsigned char i = 0;

	unsigned char inputA = 0x00;
	unsigned char inputB = 0x00;

	unsigned char total =0x00;
	unsigned char countA = 0x00;
	unsigned char countB = 0x00;

	for(i=0;i<8;i++){
		inputA = PINA;
		inputB = PINB;

		if(inputA == 0x01){
		countA = countA +1;
	}
		if(inputB ==0x01){
		countB = countB +1;
	}
		inputA = inputA >> 1;
		inputB = inputB >> 1;

}
	total = countA + countB;
	PORTC =total;


    return 1;
}
