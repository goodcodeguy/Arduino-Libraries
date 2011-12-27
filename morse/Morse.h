#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse
{
  public:
    Morse(int pin);
	Morse(int pin, int delayLength);
	void init(int pin, int delayLength);
    void dot();
    void dash();
    void showLetter(char a);
  private:
    int _pin;
	int _delayLength;
};

#endif
