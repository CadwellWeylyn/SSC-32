#include "SSC-32.h"

// SSC32 Constructor
SSC32::SSC32(void) : currentSerial(NULL), servoPin(NULL), servoPos(NULL), timeDelay(NULL),
		hasBeenInit(false)
{
}

// SSC32 Destructor
SSC32::~SSC32(void)
{
}

/*
	Function that the SSC32 will be connected to on the arduino,
	if no serialNo is specified, it's automatically 0.
*/
void SSC32::begin(int portNo, int serialNo = 0)
{
	if (hasBeenInit == false)
	{
		hasBeenInit = true;
		
		switch(serialNo)
		{
			case 0:
				Serial.begin(portNo);
				currentSerial = "Serial";
				break;
			case 1:
				Serial1.begin(portNo);
				currentSerial = "Serial1";
				break;
			case 2:
				Serial2.begin(portNo);
				currentSerial = "Serial2";
				break;
			case 3:
				Serial3.begin(portNo);
				currentSerial = "Serial3";
				break;
			default:
				hasBeenInit = false; 
				break;
		}
	}
}

void SSC32::sendToServo(void)
{
	if (currentSerial == "Serial") {
		Serial.print("#");
		Serial.print(servoPin);
		Serial.print(" P");
		Serial.print(servoPos);
		Serial.print(" T");
		Serial.println(timeDelay);
	} else if (currentSerial == "Serial1") {
		Serial1.print("#");
		Serial1.print(servoPin);
		Serial1.print(" P");
		Serial1.print(servoPos);
		Serial1.print(" T");
		Serial1.println(timeDelay);
	} else if (currentSerial == "Serial2") {
		Serial2.print("#");
		Serial2.print(servoPin);
		Serial2.print(" P");
		Serial2.print(servoPos);
		Serial2.print(" T");
		Serial2.println(timeDelay);
	} else if (currentSerial == "Serial3") {
		Serial3.print("#");
		Serial3.print(servoPin);
		Serial3.print(" P");
		Serial3.print(servoPos);
		Serial3.print(" T");
		Serial3.println(timeDelay);
	}
}

void SSC32::move(uint8_t t_servoPin, uint8_t t_servoPos, uint8_t t_timeDelay)
{
	if (t_servoPin < SSC32_MIN_SNUM || t_servoPin > SSC32_MAX_SNUM) { // Check Pin bounds
		return;
	} else if (t_servoPos < SSC32_MIN_POS || t_servoPos > SSC32_MAX_POS) { // Check Pos bounds
		return;
	} else if (t_timeDelay < SSC32_MIN_MTIME || t_timeDelay > SSC32_MAX_MTIME) { // Time bounds
		return;
	} else { // Oh, nothing must be out-of-bounds, send it to the SSC32!
		servoPin = t_servoPin;
		servoPos = t_servoPos;
		timeDelay = t_timeDelay;
		
		delay(timeDelay);
	}

	
}
