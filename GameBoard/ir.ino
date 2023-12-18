#include <IRremote.h>

const int RECV_PIN = 27;
IRrecv irrecv(RECV_PIN);
decode_results results;

void ir_setup(){
	irrecv.enableIRIn();
	irrecv.blink13(true);
}

bool detect_shot(void){
#define SecretKey 0xFF5AA5 

	if (irrecv.decode(&results) && results.value == SecretKey ){
		Serial.println(results.value, HEX);				// prints received value 
		irrecv.resume();
		return 1;
	}
	return 0;
}
