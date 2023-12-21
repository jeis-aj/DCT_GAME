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
		int led_pin ;
		int sensor_pin ;
		int state = false;		// LED light off
		int min_on_time = 1000;
		int max_on_time = 2000;

		int min_off_time = 500;
		int max_off_time = 1000;
		unsigned long int on_time = 0;
		unsigned long int off_time = 0;
	public:
		static int score ;
		// create and initialize LED TARGET Nodes
		node(int led_pin , int sensor_pin );
		// update function update led on/off for random time
		void random_update(void);
		void shot_check( void  );	// 'led on' if shot detects on that node
		bool target_shot(void);			// 'led off' if shot detects on 'random time' On led  
		void score_check(int enable);		// if true passed, game over when scored '10'
};

/* --------------------------------------------------------------------------------- */
/* SCALABLE PARAMETERS */

#define max_index 6		// max node count 
int led_arr [ max_index ] = { 7,6,5,4,3,2 };
int sensor_arr [ max_index  ] = { 14, 15 ,16, 17, 18, 19 };

#define game_switch_btn 24
#define game_score_chk_btn  26
#define trigg_delay 230 
/* --------------------------------------------------------------------------------- */
