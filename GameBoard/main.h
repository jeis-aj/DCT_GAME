/*
 *----------------------------------------------------------------------------------
 * 			DCT GUN GAME 
 *-----------------------------------------------------------------------------------
 * 	Arun jyothish k 
 *
 * 	18-12-2023 Monday
 *
 *	Main header includes all functions header
 *----------------------------------------------------------------------------------- 
 *
 */

/* ---------------------------------------------------------------------------------- */
/* CORE INCLUDES */
#include <IRremote.h>
class node {
	private:
		int led_pin ;
		int sensor_pin ;
		int state = false;		// LED light off
		int min_on_time = 1000;
		int max_on_time = 2000;

		int min_off_time = 500;
		int max_off_time = 1000;
		unsigned long int on_time = 0;
		unsigned long int off_time = 0;
		IRrecv *irrecv_ptr;
		decode_results results;
	public:
		// create and initialize LED TARGET Nodes
		node(int led_pin , int sensor_pin );
		// update function update led on/off for random time
		void update(void);
		bool  shot_check(int trigger);
		bool detect_shot(void);
		void ledOn(void);
};
bool detect_shot(void);
void ir_setup(void);

/* --------------------------------------------------------------------------------- */
/* SCALABLE PARAMETERS */
int scoredIndicator = 28;
#define max_index 6		// max node count 
int led_arr [ max_index ] = { 7,6,5,4,3,2 };
int sensor_arr [ max_index  ] = { 14, 15 ,16, 17, 18, 19 };
/* int sensor_arr [1] = { 2 }; */
/* int led_arr [1] = { 7 }; */
const int reset_btn = 24;
#define SecretKey 0xFFFFFFFF 
/* --------------------------------------------------------------------------------- */
