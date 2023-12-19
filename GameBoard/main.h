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
		int min_on_time = 200;
		int max_on_time = 1200;

		int min_off_time = 1000;
		int max_off_time = 4000;
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
};
bool detect_shot(void);
void ir_setup(void);

/* --------------------------------------------------------------------------------- */
/* SCALABLE PARAMETERS */
int scoredIndicator = 28;
/* int sensor_arr [9] = { 1,2,3,4,5,6,7,8,9 }; */
/* int led_arr [9] = { 11, 12, 13, 14, 15, 16, 17, 18,19 }; */
int sensor_arr [1] = { 2 };
int led_arr [1] = { 7 };
const int reset_btn = 25;
#define SecretKey 0xFFFFFFFF 
/* --------------------------------------------------------------------------------- */
