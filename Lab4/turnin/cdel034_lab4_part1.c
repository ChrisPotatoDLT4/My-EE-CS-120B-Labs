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
//#include "RIMS.h"
#endif
enum States{Start,buttonOne,buttonTwo}n_state;
        unsigned char press = 0x00; //A0
 //       unsigned char LedZero = 0x00; //PB0
   //     unsigned char LedOne = 0x00; //PB1

void Tick(){
	switch(n_state){
		case Start:
		n_state = buttonOne;
		break;

		case buttonOne:
		if(press == 0x01){
		n_state = buttonTwo;}
		else{n_state = buttonOne;}
		break;

		case buttonTwo:
		if(press == 0x01){
		n_state = buttonOne;}
		else{n_state = buttonTwo;}
		break;

		default :
		n_state = Start;
		break; }

	switch(n_state){
		case buttonOne:
	//	LedZero = 0x01;
	//	LedOne = 0x00;
		PORTB = 0x01;
		break;
		case buttonTwo:
	//	LedOne = 0x02;
	//	LedZero = 0x00;
		PORTB = 0x02;
		break;

		default:
		break;	}
}


int main(void) {
//	enum States(Start,buttonOne,buttonTwo)n_state;
    
	DDRA = 0xFE; //Button Input PA0 1111 1110
	PORTA = 0x01;

	DDRB = 0x03; //LED output PB0 and PB1 0000 0011
	PORTB = 0xFC;
/*
	unsigned char press = 0x00; //A0
	unsigned char LedZero = 0x00; //PB0
	unsigned char LedOne = 0x00; //PB1 */
	n_state = Start;

    while (1) {
	Tick();	
	press = PINA & 0x01; //A0	
//	LedZero = PINB & 0x01; //PB0
//	LedOne = PINB & 0x02; //PB1

//	Tick();
    }
    return 1;
}
