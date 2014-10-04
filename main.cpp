#include "arduino.h"

int count;

// the setup routine runs once when you press reset:

void setup() {
	// initialize serial communication at 115200 bits per second:
	Serial.begin(115200);

	count = 0;
}

// the loop routine runs over and over again forever:

void loop() {
	aprintf("{\"azimuth\": %d, \"altitude\": %d, \"twist\": %d}", count, 3600-count, (1800+count)%3600);
	Serial.write(0);

	count += 10;

	if (count >= 3600) {
		count = 0;
	}

	delay(40);
}


