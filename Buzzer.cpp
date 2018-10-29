#include "buzzer.h"


void initBuzzer(){
  
   DDRE |= (1<<DDE5); //pin 3
}

void turnBuzzerOn(unsigned char data){
  PORTE = (PORTE & 0xF0) | (data & 0x0F);// feel free to modify this code. Not sure if its correct. 
}
