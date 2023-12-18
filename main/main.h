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
		int min_on_time = 500;
		int max_on_time = 1000;

		int min_off_time = 500;
		int max_off_time = 1000;
		unsigned long int on_time;
		unsigned long int off_time;
	public:
		// create and initialize LED TARGET Nodes
		node(int led_pin , int sensor_pin );
		// update function update led on/off for random time
		void update(void);
		bool  shot_check(int trigger);
};
bool detect_shot();


/* --------------------------------------------------------------------------------- */
/* SCALABLE PARAMETERS */
int sensor_arr [9] = { 1,2,3,4,5,6,7,8,9 };
int led_arr [9] = { 11, 12, 13, 14, 15, 16, 17, 18,19 };
const int reset_btn = 25;
/* --------------------------------------------------------------------------------- */
