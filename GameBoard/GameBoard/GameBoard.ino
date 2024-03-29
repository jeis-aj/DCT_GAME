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

class node *node_ptr = malloc( sizeof(node)*max_index );		// mem alloc for node pointers
void setup(){
	pinMode( game_switch_btn , INPUT_PULLUP );
	pinMode( game_score_chk_btn , INPUT_PULLUP );
	Serial.begin(115200);
	for( int index = 0; index < max_index ; ++index  ){
		int sensor_pin = sensor_arr[index]	;
		int led_pin = led_arr[index]	;

		/* node_ptr[index] =  n1.this; */
		node_ptr[index]  =*(new node(led_pin, sensor_pin));
	}
}

void loop(){
	bool shot_detected = 0;

	// update led status (toggle random time)
	for ( int index = 0 ; index < max_index ; ++index ){
		// update score if shot on 'On target' 
		bool is_target_shot_mode = digitalRead( game_switch_btn ) == 0;

		if ( is_target_shot_mode ){
			shot_detected = node_ptr[index].target_shot();	} 

		// shot to light target, score if shot on any target 
		else {
			shot_detected = node_ptr[index].shot_check();
		}

		if ( digitalRead (game_score_chk_btn) == 0 )
			score_check( shot_detected  ); 	// if true passed, game over when 10 scored
	}
}

void node::random_update(void){
	unsigned long int time  = millis();
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
}

bool node::target_shot(void){
	random_update();
	bool trigger =  !digitalRead (sensor_pin) ;	// ir shot detect == true
	if ( trigger && state){		// detects shot if, for particular node led on and shot on node
		on_time -= max_on_time;	// trick time to turn off led, shot on target - led off
		Serial.print("shot");				// prints received value 
		/* state = false; */
		/* delay(trigg_delay); */
		return true;
	}
	return false;
}

bool node::shot_check( void  ){
	if (  digitalRead( sensor_pin ) == 0 ){
		digitalWrite( led_pin , LOW );
		Serial.print("shot");
		delay(trigg_delay);
		digitalWrite( led_pin , HIGH);
		return true;
	}
	digitalWrite( led_pin , HIGH);
	return false;
}

void score_check(int trigger )		// if true passed, game over when scored '10'
{ 
	static int score = 0;
	if ( trigger ){
		score++; }
	while( score > 9 ); 
}


