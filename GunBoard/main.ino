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

int max_attempt_count = 8;		 // max attempt for a person
int empty_bullet_indicator = 13;
int led_arr[max_attempt] = {4,5,6,7,8,9,10,11};			// led pins

void setup()
{
	for(led_pin: led_arr){
		pinMode( led_pin, OUTPUT );
	}
	pinMode( trigger_pin, INPUT_PULLUP);
}

int count = 0 ;
void loop() {
	if ( digitalRead(trigger_pin) == HIGH);
		return;

	if ( count < max_attempt  ){
		digitalWrite( Reloading_ledPin, LOW);
		print("Bullet....");
		println(count);
		irsend.sendNEC(0xAF5E827, 32);
		digitalWrite( led_arr[count], LOW);
		++count;
	}
	else{
		for(led_pin: led_arr){
			digitalWrite( led_pin, HIGH);
		}
		digitalWrite( Reloading_ledPin, HIGH );
		println("Reloading....");
		count = 0 ;
		delay(10000);		// 10 seconds Reloading delay
	}

}
