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

#include "main.h"
#include <time.h> 

class node {
	private:
		int state = false;		// LED light off
		int rand_on_time_minimum = 500;
		int rand_on_time_deviation = 500;

		int rand_off_time_minimum = 500;
		int rand_off_time_deviation = 500;
	public:
		unsigned long int on_time;
		unsigned long int off_time;

	node(int led_pin , int sensor_pin ) {
		digitalWrite( led_pin, 	HIGH   );	// led ON
		pinMode(   led_pin, 	OUTPUT );
		pinMode(   sensor_pin , INPUT  );
	}
	/*
	* update function update led on/off for random time
	*
	*/
	void update(void);
};

int sensor_arr [9] = { 1,2,3,4,5,6,7,8,9 };
int led_arr [9] = { 11, 12, 13, 14, 15, 16, 17, 18,19 };

void setup(){
	node_matrix[[]] ; 
	for(  )
}

void loop(){

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
		state = false;
		digitalWrite( led_pin, 	LOW	);		// turn on led
	}
}


