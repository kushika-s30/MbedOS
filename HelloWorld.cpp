//The Hello World of Microcontroller: Blinking LEDs sequentially
//Code written by Kushika Sivaprakasam 

#include "mbed.h"

DigitalOut first_LED(LED1);
DigitalOut second_LED(LED2);
DigitalOut third_LED(LED3);

int main(){
  while(1){
    first_LED=1;
    wait(1);
    first_LED=0;
    
    second_LED=1;
    wait(1);
    second_LED=0;
    
    third_LED=1;
    wait(1);
    first_LED=0;
  }
}
    
