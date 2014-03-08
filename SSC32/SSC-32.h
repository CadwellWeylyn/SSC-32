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
	SSC32(void);
	~SSC32(void);

	void begin(int portNo, int serialNo);
	void sendToServo(void);

	void move(uint8_t t_servoPin, uint8_t t_servoPos, uint8_t t_timeDelay);

private:
	char* currentSerial;
	uint8_t servoPin;
	uint8_t servoPos;
	uint8_t timeDelay;
	bool hasBeenInit;
};
