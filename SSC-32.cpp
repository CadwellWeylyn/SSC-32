#include "SSC-32.h"

// SSC32 Constructor
SSC32::SSC32() : currentSerial(NULL), servoPin(NULL), pos(NULL), time(NULL),
		 hasBeenInit(false)
{
}

// SSC32 Destructor
SSC32::~SSC32()
{
}

/*
	Function that the SSC32 will be connected to on the arduino,
	if no serialNo is specified, it's automatically 0.
*/
void SSC32::Begin(int portNo, int serialNo = 0)
{
	if (hasBeenInit == false)
	{
		hasBeenInit = true;
		
		switch(serialNo)
		{
			case 0:
				Serial.begin(portNo);
				currentSerial = 'Serial';
				break;
			case 1:
				Serial1.begin(portNo);
				currentSerial = 'Serial1';
				break;
			case 2:
				Serial2.begin(portNo);
				currentSerial = 'Serial2';
				break;
			case 3:
				Serial3.begin(portNo);
				currentSerial = 'Serial3';
				break;
			default:
				hasBeenInit = false; 
				break;
		}
	}
}

void SSC32::print(char* message)
{
	if (currentSerial == 'Serial') {
		Serial.print(message);
	} else if (currentSerial == 'Serial1') {
		Serial1.print(message);
	} else if (currentSerial == 'Serial2') {
		Serial2.print(message);
	} else if (currentSerial == 'Serial3') {
		Serial3.print(message);
	}
}

void SSC32::println(char* message)
{
	if (currentSerial == 'Serial') {
		Serial.println(message);
	} else if (currentSerial == 'Serial1) {
		Serial1.println(message);
	} else if (currentSerial == 'Serial2') {
		Serial2.println(message);
	} else if (currrentSerial == 'Serial3') {
		Serial3.println(message);
	}
}

void SSC32::move(int servoPin, int servoPos, int timeDelay)
{
	if (servoPin < SSC32_MIN_SNUM || servoPin > SSC32_MAX_SNUM) { // Check Pin bounds
		return;
	} else if (servoPos < SSC32_MIN_POS || servoPos > SSC32_MAX_POS) { // Check Pos bounds
		return;
	} else if (timeDelay < SSC32_MIN_MTIME || timeDelay > SSC32_MAX_MTIME) { // Check Time bounds
		return;
	} else { // Oh, nothing must be out-of-bounds, send it to the SSC32!
		SSC32::print("#");
		SSC32::print(servoPin);
		SSC32::print(" P");
		SSC32::print(servoPos);
		SSC32::print(" T");
		SSC32::print(timeDelay);
		SSC32::println();
		delay(timeDelay);
	}

	
}
