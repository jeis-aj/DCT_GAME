/*
 *----------------------------------------------
 * 			DCT GUN GAME 
 *----------------------------------------------
 * 	Arun jyothish k 
 *
 * 	18-12-2023 Monday
 *
 *	Main header includes all functions header
 *----------------------------------------------
 *
 */

#include <time.h> 
#include "main.h"


int max_index = sizeof(sensor_arr)/sizeof(sensor_arr[0]);		// max node count 

class node *node_ptr = malloc( sizeof(node)*max_index );		// mem alloc for node pointers

void setup(){
	pinMode( scoredIndicator, OUTPUT);
	Serial.begin(115200);
	pinMode (reset_btn , INPUT_PULLUP);
	for( int index = 0; index < max_index ; ++index  ){
		int sensor_pin = sensor_arr[index]	;
		int led_pin = led_arr[index]	;
		
		/* node_ptr[index] =  n1.this; */
		node_ptr[index]  =*(new node(led_pin, sensor_pin));
	}
}

int score = 0;
void loop(){
		// update led status (toggle random time)
		for ( int index = 0 ; index < max_index ; ++index ){
		if (reset_btn == 0){
			score = 0;
			return; }
		node_ptr[index].update();					// update led status (toggle random time)
		bool isScored  = node_ptr[index].detect_shot();					// update score if shot on target, return true if scored
		if ( isScored ){
			digitalWrite( scoredIndicator, HIGH );
			score++;
		}
		else{
			digitalWrite( scoredIndicator, HIGH );
		}
	}
	/* Serial.print("Score: "); */
	/* Serial.println(score); */
}

void node::update(void){
	unsigned long int time  = millis();
	/* Serial.println(on_time); */
	if ( state &&  on_time < time ){
		// led off time duration randomly sets,  every time turns off
		off_time = time + random(min_off_time, max_off_time );
		state = false;					// turn off led == status false
		digitalWrite( led_pin, 	HIGH   );		// turn off led
	}
	if ( !state && off_time < time ){
		// led on time duration randomly sets,  every time turns on 
		on_time = time + random(min_on_time, max_on_time );
		state = true ;					// turn on led == status true
		digitalWrite( led_pin, 	LOW	);		// turn on led
	}
}


node::node(int led_pin , int sensor_pin ) {
	this->led_pin = led_pin;
	this->sensor_pin = sensor_pin;
	digitalWrite( led_pin, 	HIGH   );	// led ON
	pinMode(   led_pin, 	OUTPUT );
	pinMode(   sensor_pin , INPUT  );
	irrecv_ptr = new IRrecv(sensor_pin);
	irrecv_ptr->enableIRIn();
}

bool node::detect_shot(void){
	if (irrecv_ptr->decode(&results)){
		Serial.println(results.value, HEX);				// prints received value 
		irrecv_ptr->resume();
		/* bool trigger = (results.value == SecretKey); */
		bool trigger = true ;
		if ( trigger && state){
			/* state = false;					// turn off led == status false */
			/* digitalWrite( led_pin, 	HIGH);		// turn off led */
			on_time -= max_on_time;							// trick time to turn off led, shot on target - led off
			Serial.print("shot");				// prints received value 
			return true;
		}
		else{
			delay(100);
			/* digitalWrite( led_pin, 	HIGH);		// turn off led */
		}
		return false;
	}
}
