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
class node {
	private:
		int led_pin , sensor_pin ;
		int state = false;		// LED light off
		int rand_on_time_minimum = 500;
		int rand_on_time_deviation = 500;

		int rand_off_time_minimum = 500;
		int rand_off_time_deviation = 500;
		unsigned long int on_time;
		unsigned long int off_time;
	public:
		// create and initialize LED TARGET Nodes
		node(int led_pin , int sensor_pin );
		// update function update led on/off for random time
		void update(void);
		bool  shot_check(int trigger);
};



/* --------------------------------------------------------------------------------- */
/* SCALABLE PARAMETERS */
int sensor_arr [9] = { 1,2,3,4,5,6,7,8,9 };
int led_arr [9] = { 11, 12, 13, 14, 15, 16, 17, 18,19 };
const int reset_btn = 25;
/* --------------------------------------------------------------------------------- */
