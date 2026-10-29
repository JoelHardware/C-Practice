#include <stdio.h>
#include <avr/io.h>

int main(){
    DDRB = 0xFF;
    DDRC = 0x00;

    while(1){
        if(PINC & 0b00010000){
            PORTB =0x55;
        }else{
            PORTB = 0xAA
        }
    }
    return 0;

}