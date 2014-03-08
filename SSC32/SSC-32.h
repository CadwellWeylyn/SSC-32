#include <Arduino.h>

#define SSC32_MIN_POS 500
#define SSC32_MAX_POS 2500

#define SSC32_MIN_SNUM 0
#define SSC32_MAX_SNUM 31

#define SSC32_MIN_MTIME 1
#define SSC32_MAX_MTIME 65535

class SSC32
{
public:
	SSC32();
	~SSC32();

	void begin(int portNo, int serialNo = 0);
	void print(char* message);
	void println(char* message);

	void move(int servoPin, int servoPos, int timeDelay);

private:
	char* currentSerial;
	// uint8_t servoPin;
	// uint8_t servoPos;
	// uint8_t timeDelay;
	bool hasBeenInit;
};
