#include "Arduino.h"
#include "LedAnim.h"

#define DEFAULT_SPEED 1000

LedAnim::LedAnim(int startPin, int endPin)
{
	init(startPin, endPin, DEFAULT_SPEED);
}

LedAnim::LedAnim(int startPin, int endPin, int delayLength)
{
	init(startPin, endPin, delayLength);
}

void LedAnim::init(int startPin, int endPin, int delayLength)
{
	_startPin = startPin;
	_endPin = endPin;
	_delayLength = delayLength;
	
	setupLEDs();
}

void LedAnim::setupLEDs()
{
	for(int i = _startPin; i <= _endPin; i++)
	{	
		pinMode(i, OUTPUT);
	}
}

void LedAnim::setSpeed(int speed)
{
	_delayLength = speed;
}

void LedAnim::OneAtATimeAll()
{
	
	if(_endPin > _startPin)
	{
		for(int i = _startPin; i <= _endPin; i++)
		{
			Serial.println(i);
			digitalWrite(i, HIGH);
			delay(_delayLength);
		}
	
		delay(_delayLength * 5);
	
		resetLEDs();
	}
}

void LedAnim::OneAtATime()
{
	for(int i = _startPin; i <= _endPin; i++)
	{
		if(i > _startPin)
		{
			digitalWrite(i - 1, LOW);
		}
		
		digitalWrite(i, HIGH);
		delay(_delayLength);
	}
	
	resetLEDs();
}

void LedAnim::StartToEndAndBack()
{
	for(int i = _startPin; i <= _endPin; i++)
	{
		if(i > _startPin)
		{
			digitalWrite(i - 1, LOW);
		}
		
		digitalWrite(i, HIGH);
		delay(_delayLength);
	}
	
	for(int i = _endPin - 1; i >= _startPin; i--)
	{
		if(i < _endPin)
		{
			digitalWrite(i + 1, LOW);
		}
		
		digitalWrite(i, HIGH);
		delay(_delayLength);
	}
	
	resetLEDs();
}

void LedAnim::BinaryCounter()
{

	if(digitalRead(_startPin) == LOW)
	{
		digitalWrite(_startPin, HIGH);
	}
	else
	{
		int n = _startPin;
		
		while(digitalRead(n) == HIGH && n <= _endPin)
		{
			digitalWrite(n, LOW);
			n++;
		}
		
		digitalWrite(n, HIGH);
	}
	
	delay(_delayLength);
}

void LedAnim::resetLEDs()
{
	for(int i = _startPin; i <= _endPin; i++)
	{
		digitalWrite(i, LOW);
	}
}