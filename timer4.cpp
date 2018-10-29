#include "timer4.h"

void initTimer4(){
  TCCR4A |= (1 << WGM40);//correct PWM mode(frequency): WGM40 sets as 1
  TCCR4A &= ~(1 << WGM41);//correct PWM mode(frequency): WGM41 sets as 0
  TCCR4B &= ~(1 << WGM42);//correct PWM mode(frequency): WGM40 sets as 0
  TCCR4B |= (1 << WGM43);//correct PWM mode(frequency): WGM40 sets as 1
}
