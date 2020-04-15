#include <Arduino.h>

#define potZgrzew     A6
#define potChlodz     A7
#define przekMagnesu  A0
#define przekGrzalki  A1
#define przyciskNozny A3

int czasZgrzewania()
{
	int val = analogRead(potZgrzew);
	val = map(val, 0, 1024, 0, 4000);
	return val;
}

int czasChlodzenia()
{
	int val = analogRead(potChlodz);
	val = map(val, 0, 1024, 0, 4000);
	return val;
}

bool wcisniete()
{
	if (digitalRead(przyciskNozny)) return 1;
	else return 0;
}

void setup()
{
	pinMode(potChlodz, INPUT);
	pinMode(potZgrzew, INPUT);
	pinMode(przyciskNozny, INPUT_PULLUP);
	pinMode(przekGrzalki, OUTPUT);
	pinMode(przekMagnesu, OUTPUT);
}

void loop()
{
	if (wcisniete()) delay(50);
	if (wcisniete())
	{
		digitalWrite(przekGrzalki, HIGH);
		digitalWrite(przekMagnesu, HIGH);
		delay(czasZgrzewania());
		digitalWrite(przekGrzalki, LOW);
		delay(czasChlodzenia);
		digitalWrite(przekMagnesu, LOW);
	}
}
