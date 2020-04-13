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


         DDRA = 0x00;    //Configure port A's 8 pins to be inputs
        PORTA = 0xFF;   //Haveing this to be output pins

        DDRB = 0xFF;    //configure port B's 8 pins t be outputs
        PORTB = 0x00;

        unsigned char doorSensor = 0x00; //PA0
        unsigned char lightSensor= 0x00; //PA1


        while(1){
                 doorSensor = PINA & 0x01; //Pin A bit 0 will have doorSensor
                lightSensor = PINA & 0x02; //Pin A bit 1 will have lightSensor

                if( doorSensor && (!lightSensor) )
                {
                        PORTB = 0x01; //PORTB will be outputing the value (writing)
                }                        //PORTB will output a number either 1 or 0
                else {PORTB = 0x00;}
        }

    return 1;
}
