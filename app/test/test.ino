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

void loop(){
	count  = 0;	
	for ( int ir: irs ){
		if (  !digitalRead( ir ) ){
			digitalWrite( led_arr[count], LOW );
			Serial.print("shot");
			delay(300);
		}
			digitalWrite( led_arr[count] , HIGH);
		count ++;	
	}
	/*
	for ( String msg : arr ){
	if ( count > 50 && msg=="shot")
		continue;
		Serial.println("shot");
	Serial.println(count);
	count++;

	}
	*/
}
