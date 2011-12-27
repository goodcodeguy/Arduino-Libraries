#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
  Morse(pin, 250);
}

Morse::Morse(int pin, int delayLength)
{
	pinMode(pin, OUTPUT);
	_pin = pin;
	_delayLength = delayLength;
}

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(_delayLength);
  digitalWrite(_pin, LOW);
  delay(_delayLength);
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(_delayLength * 4);
  digitalWrite(_pin, LOW);
  delay(_delayLength);
}


void Morse::showLetter(char a)
{
	Serial.print("showing ");
	Serial.println(a);
  switch(a)
  {
    case 'a':
      dot(); dash();
    break;
    
    case 'b':
      dash(); dot(); dot(); dot();
    break;
    
    case 'c':
      dash(); dot(); dash(); dot();
    break;
    
    case 'd':
      dash(); dot(); dot();
    break;
    
    case 'e':
      dot();
    break;
    
    case 'f':
      dot(); dot(); dash(); dot();
    break;
    
    case 'g':
      dash(); dash(); dot();
    break;
    
    case 'h':
      dot(); dot(); dot(); dot();
    break;
    
    case 'i':
      dot(); dot();
    break;
    
    case 'j':
      dot(); dash(); dash(); dash();
    break;
    
    case 'k':
      dash(); dot(); dash();
    break;
    
    case 'l':
      dot(); dash(); dot(); dot();
    break;
    
    case 'm':
      dash(); dash();
    break;
    
    case 'n':
      dash(); dot();
    break;
    
    case 'o':
      dash(); dash(); dash();
    break;
    
    case 'p':
      dot(); dash(); dash(); dot();
    break;
    
    case 'q':
      dash(); dash(); dot(); dash();
    break;
    
    case 'r':
      dot(); dash(); dot();
    break;
    
    case 's':
      dot(); dot(); dot();
    break;
    
    case 't':
      dash();
    break;
    
    case 'u':
      dot(); dot(); dash();
    break;
    
    case 'v':
      dot(); dot(); dot(); dash();
    break;
    
    case 'w':
      dot(); dash(); dash();
    break;
    
    case 'x':
      dash(); dot(); dot(); dash();
    break;
    
    case 'y':
      dash(); dot(); dash(); dash();
    break;
    
    case 'z':
      dash(); dot(); dash(); dot();
    break;
    
    default:
	Serial.println("no letter");
    break;
    
  }
}
