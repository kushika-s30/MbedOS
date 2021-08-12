// STALKER ALARM using mbed LPC1768 and SRF08 Ultrasonic Sensor via I2C Interface
// Code Written by Kushika Sivaprakasam

#include "mbed.h"

I2C rangefinder(p9, p10); //sda, sc1
Serial pc(USBTX, USBRX); //tx, rx
const int addr = 0xE0;
char config_r[2];
char range_read[2];
float range;
DigitalOut vibration_motor(p30);

int main() {
    while (1) {
        config_r[0] = 0x00; //set pointer reg to ’cmd register’
        config_r[1] = 0x51; //initialise, result in cm
        rangefinder.write(addr, config_r, 2);
        wait(0.07);
        config_r[0] = 0x02; //set pointer reg to ’data register’
        rangefinder.write(addr, config_r, 1); //send to pointer ’read range’
        rangefinder.read(addr, range_read, 2); //read the two-byte range data
        range = ((range_read[0] << 8) + range_read[1]);
        //pc.printf("Range = %.2f cm\n\r", range); //print range on screen
        if(range<=60){
            vibration_motor=1; //turn ON vibration motor
            wait(5); //vibrates for 5 seconds
            vibration_motor=0; // turn OFF vibration motor
        }    
        wait(0.05);
    }
}
