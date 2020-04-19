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
enum States{Start,CheckAll,buttonA0,buttonA1, pressBoth}n_state; 
        unsigned char incrementButton = 0x00; //PA0
        unsigned char decrementButton = 0x00; //PA1

        unsigned char outputC = 0x07; //will be initially at 7   


void Tick(){
	switch(n_state){
		case Start:
		n_state = CheckAll;
		break;

		case CheckAll:
                if( ((incrementButton + decrementButton ==0x03)) ){
                        n_state = pressBoth;
                }
		 else if((incrementButton == 0x01) ){
			n_state = buttonA0;
		}
		else if(decrementButton == 0x02){
			n_state = buttonA1;
		}
		break;
		default:
		n_state = Start;
		break;
	}
	////////////////////////////////////////////////
	switch(n_state){
		case buttonA0:			
			if(outputC < 9){
			outputC= outputC + 1;
			PORTC = outputC;}
			n_state = CheckAll;
		break;

		case buttonA1:	
			if(outputC >0){
			outputC= outputC - 1;
			PORTC = outputC;}
			n_state = CheckAll;
		break;

                case pressBoth:
                        outputC = 0x00;
                        PORTC = outputC;
//		n_state = CheckAll;
                break;

		default :
		break;
	}
}


int main(void){

	DDRA = 0xF0;
	PORTA = 0x0F;

	DDRC = 0x0F;
	PORTC = 0xF0;
	n_state = Start;

	while(1){
		incrementButton = PINA & 0x01; //PA0
		decrementButton = PINA & 0x02; //PA1

	Tick();

	}



    return 1;
}
