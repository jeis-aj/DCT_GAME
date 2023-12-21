int irs [] = { 14, 15, 16 ,17 ,18, 19 };
int led_arr [] = { 7, 6, 5, 4, 3, 2, 1};

int count = 0;
void setup(){
	Serial.begin(115200);
	int count  = 0;	
	for ( int ir: irs ){
		pinMode( ir, INPUT);
		pinMode( led_arr[count] , OUTPUT);
		count++;
	}
}

