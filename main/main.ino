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
	pinMode (reset_btn , INPUT_PULLUP);
	for( int index = 0; index < max_index ; ++index  ){
		int sensor_pin = sensor_arr[index]	;
		int led_pin = led_arr[index]	;
		node_ptr[index] = node(led_pin, sensor_pin);
	}
}


void loop(){
	for ( int index = 0 ; index < max_index ; ++index ){
		if (reset_btn == 0){
			return; }
		node_ptr[index].update();					// update led status (toggle random time)
		node_ptr[index].shot_check(1);					// update score if shot on target
	}
}

void node::update(void){
	long int time  = millis();
	if ( state && on_time < time ){
		// led off time duration randomly sets,  every time turns off
		off_time = rand_off_time_minimum + rand() % rand_off_time_deviation ;	
		state = false;					// turn off led == status false
		digitalWrite( led_pin, 	HIGH   );		// turn off led
	}
	if ( !state && on_time < time ){
		// led on time duration randomly sets,  every time turns on 
		on_time = rand_on_time_minimum + rand() % rand_on_time_deviation ;
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
