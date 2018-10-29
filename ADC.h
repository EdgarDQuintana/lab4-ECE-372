// Author:         
// Net ID:         
// Date:           
// Assignment:     Lab 4
//----------------------------------------------------------------------//

#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

int AnalogRead(int AnalogPin);
void AnalogReadResoltion(unisgned char bits);
void AnalogReference(unsigned char Type);
#endif
