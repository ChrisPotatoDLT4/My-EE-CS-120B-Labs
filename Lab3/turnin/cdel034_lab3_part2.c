
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


        DDRA = 0xF0;
        PORTA = 0x0F;

        DDRC = 0x7F;// 0111 1111
        PORTC = 0x80;

        unsigned char fuelLevelOne = 0x00; //PA0
        unsigned char fuelLevelTwo = 0x00; //PA1
        unsigned char fuelLevelThree = 0x00; //PA2
        unsigned char fuelLevelFour = 0x00; //PA3
	unsigned char totalFuel = 0x00;
	unsigned char holdValue = 0x00;
/*
 *         unsigned char keyIgnition = 0x00 // PA4
 *                 unsigned char driverSeat = 0x00 // PA5
 *                         unsigned char driverSeatbelt = 0x00 //PA6
 *
 *                         PC7 will be 1 if PA4 = 1, PA5 = 1 but PA6 = 0
 *
 *                         */





while(1){

        fuelLevelOne = PINA & 0x01; //pin 0
        fuelLevelTwo = PINA & 0x02; //pin 1  0000
        fuelLevelThree = PINA & 0x04; //pin2
        fuelLevelFour = PINA & 0x08; //pin3

	totalFuel = fuelLevelOne + fuelLevelTwo + fuelLevelThree + fuelLevelFour;
        //1-2       //0111 1111
        if(totalFuel == 0x00){
		holdValue = 0x40;
	}
         else if((totalFuel == 0x01) || (totalFuel == 0x02) ){
        	 holdValue = 0x60;
         }
         //3-4 change || to +
        else if( ( (totalFuel ) ==0x03) || (totalFuel == 0x04) ){
        	holdValue = 0x70;
         }
         //5-6 0101  0110
         else if (((totalFuel) == 0x05) || ((totalFuel)==0x06)){
        	 holdValue = 0x38;
	}
	//7-9
	else if( ((totalFuel) == 0x07) || ((totalFuel)==0x08) || ((totalFuel)==0x09) ){
                holdValue = 0x3C;
        }
	//10-12
	else if( ((totalFuel)==0x0A) || ((totalFuel)==0x0B) || ((totalFuel)==0x0C) ){
                holdValue = 0x3E;
        }
	//13-15
	else if(((totalFuel) == 0x0D) || ((totalFuel) ==0x0E) || ((totalFuel)==0x0F) ){
                holdValue = 0x3F;
        }
	PORTC = holdValue;
}

return 1;
}

