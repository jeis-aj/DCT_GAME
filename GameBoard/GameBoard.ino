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
class node *node_ptr;

void setup(){
	ir_setup();
	pinMode( scoredIndicator, OUTPUT);
	Serial.begin(9600);
	pinMode (reset_btn , INPUT_PULLUP);
	for( int index = 0; index < max_index ; ++index  ){
		int sensor_pin = sensor_arr[index]	;
		int led_pin = led_arr[index]	;
		node_ptr[index] = node(led_pin, sensor_pin);
	}
}

int score = 0;
void loop(){
	for ( int index = 0 ; index < max_index ; ++index ){
		if (reset_btn == 0){
			score = 0;
			return; }
		node_ptr[index].update();					// update led status (toggle random time)
		bool isScored  = node_ptr[index].shot_check(detect_shot());					// update score if shot on target, return true if scored
		if ( isScored ){
			digitalWrite( scoredIndicator, HIGH );
			score++;
		}
		else{
			digitalWrite( scoredIndicator, HIGH );
		}
	}
	Serial.print("Score: ");
	Serial.println(score);
}

void node::update(void){
	long int time  = millis();
	if ( state && on_time < time ){
		// led off time duration randomly sets,  every time turns off
		off_time = random(min_off_time, max_off_time );
		state = false;					// turn off led == status false
		digitalWrite( led_pin, 	HIGH   );		// turn off led
	}
	if ( !state && on_time < time ){
		// led on time duration randomly sets,  every time turns on 
		on_time = random(min_on_time, max_on_time );
		state = true ;					// turn on led == status true
		digitalWrite( led_pin, 	LOW	);		// turn on led
	}
}

bool  node::shot_check(int trigger){
	if ( trigger && state){
		state = false;					// turn off led == status false
		digitalWrite( led_pin, 	HIGH   );		// turn off led
		return 1; }
	return 0;	
}

node::node(int led_pin , int sensor_pin ) {
	this->led_pin = led_pin;
	this->sensor_pin = sensor_pin;
	digitalWrite( led_pin, 	HIGH   );	// led ON
	pinMode(   led_pin, 	OUTPUT );
	pinMode(   sensor_pin , INPUT  );
}


