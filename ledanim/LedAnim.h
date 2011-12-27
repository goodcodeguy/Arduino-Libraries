#ifndef LedAnim_h
#define LedAnim_h

#include "Arduino.h"

class LedAnim
{
	int _startPin, _endPin, _delayLength;
	
	public:
		LedAnim(int startPin, int endPin);
		LedAnim(int startPin, int endPin, int delayLength);
		void init(int startPin, int endPin, int delayLength);
		void resetLEDs();
		void setupLEDs();
		void setSpeed(int speed);
		void OneAtATimeAll();
		void OneAtATime();
		void StartToEndAndBack();
		void BinaryCounter();
};

#endif