/*----------------------------------------------------------------
 *		Arun jyothish k 
 *		Project: Gun Game Code
 *		code intented: Gun 
 *		date: 18-12-2023 Monday
 *----------------------------------------------------------------*/

/*----------------------------------------------------------------*/

// ir blaster pin 3 ////
#include <IRremote.h>

IRsend irsend;

const int max_attempt_count = 8;		 // Max attempt for a person
const int trigger_pin = 2;			// Trigger button pin
int Reloading_ledPin = 13;			// Reloading LED Indicator 
int led_arr[max_attempt_count] = {4,5,6,7,8,9,10,11,12};			// led pins

void setup()
{
	for(int led_pin: led_arr){
		pinMode( led_pin, OUTPUT );
	}
	pinMode( trigger_pin, INPUT_PULLUP);
}

int count = 0 ;
void loop() {
	if ( digitalRead(trigger_pin) == HIGH) 
		return;

	if ( count < max_attempt_count  ){
		digitalWrite( Reloading_ledPin, LOW);
		Serial.print("Bullet....");
		Serial.println(count);
		irsend.sendNEC(0xAF5E827, 32);
		digitalWrite( led_arr[count], LOW);
		++count;
	}
	else{
		/*
		for(int led_pin: led_arr){
			digitalWrite( led_pin, HIGH);
			delay(1000);		// 10 seconds Reloading delay
		}
		*/

		digitalWrite( Reloading_ledPin, HIGH );
		Serial.println("Reloading....");
		count = 0 ;
		reload_animation();
	}

}
#define max_animation_count 5
void reload_animation(void) {
	for ( int count = 0; count < max_animation_count ; ++count ){
		for(int led_pin: led_arr){
			digitalWrite( led_pin, HIGH);
			delay(100);
		}
			delay(400);
		for(int led_pin: led_arr){
			digitalWrite( led_pin, LOW);
			delay(100);
		}
	}
}
