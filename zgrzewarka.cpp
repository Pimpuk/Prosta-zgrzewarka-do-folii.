/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

#define potZgrzew     A7
#define potChlodz     A6
#define przekMagnesu  A1
#define przekGrzalki  A0
#define przyciskNozny A3

int czasZgrzewania()
{
	int val = analogRead(potZgrzew);
	val = map(val, 0, 1024, 1000, 4000);
	return val;
}

int czasChlodzenia()
{
	int val = analogRead(potChlodz);
	val = map(val, 0, 1024, 1000, 4000);
	return val;
}

void setup()
{
	pinMode(potChlodz, INPUT);
	pinMode(potZgrzew, INPUT);
	pinMode(przyciskNozny, INPUT_PULLUP);
	pinMode(przekGrzalki, OUTPUT);
	pinMode(przekMagnesu, OUTPUT);
	digitalWrite(przekGrzalki, HIGH);
	digitalWrite(przekMagnesu, HIGH);
}

void loop()
{
	int T1 = czasZgrzewania();
	int T2 = czasChlodzenia();
	digitalWrite(przekGrzalki, HIGH);
	digitalWrite(przekMagnesu, HIGH);
	
	
	if (digitalRead(przyciskNozny)==LOW){
		delay(50);
		if (digitalRead(przyciskNozny==LOW)){
			digitalWrite(przekGrzalki, LOW);
			digitalWrite(przekMagnesu, LOW);
			delay(T1);
			digitalWrite(przekGrzalki, HIGH);
			delay(T2);
			digitalWrite(przekMagnesu, HIGH);
			delay(1000);// czas na otwarczie sie szczek
		}		
	}
}
