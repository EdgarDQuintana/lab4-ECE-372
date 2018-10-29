#include <Arduino.h>
#include <avr/io.h>
#include "switch.h"
#include "timer0.h"

unsigned int delay_val = 100; 
unsigned int delayState = 100;
 // Define a set of states that can be used in the state machine using an enum
 // create states
typedef enum stateType_enum {
  wait_press, debounce_press, wait_release, debounce_release
} stateType;

//initialize states
volatile stateType state = wait_press;

int main(){
  initSwitchPB3(); //might be more useful than statement above
  initTimer0();//Turn on the timer interrupt
  sei(); // enable global interrupts

  /*
  * Implement a state machine in the while loop which achieves the assignment
  * requirements.
  */
 int i = 0;
  while(1){

    // for(unsigned char i = 0; i < 16; i++){
      
      i++;
      if(i > 16){
        i = 0;
      }
      delayMs(delay_val);

    // }

    // After 100 ms, increment the binary number represented by the LEDs
    //for switch debounce, to avoid the on/off/on/off that occurs when turning on switch
     switch(state){
      case wait_press:
        break;
      case debounce_press:
        delayMs(delayState);
        state = wait_release;
        break;
      case wait_release:
        break;
      case debounce_release:
        delayMs(delayState);
        state = wait_press;
        delay_val = 300 - delay_val;
        
        break;
    }
  }
  return 0;
}


ISR(PCINT0_vect){  
  //pin3 pb3
  if(state == wait_press){
  state = debounce_press;
  }
  else if(state == wait_release){
    PORTB ^= (1 << PORTB7);
    state = debounce_release;
  }
