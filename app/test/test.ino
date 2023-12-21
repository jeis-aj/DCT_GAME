void setup(){
	Serial.begin(115200);
}
String arr[] = {"hello ", "hey", "how", "find", "shot"," put", "local"};
int count = 0;
void loop(){
	/*
	for ( String msg : arr ){
	if ( count > 50 && msg=="shot")
		continue;
		Serial.println("shot");
	Serial.println(count);
	count++;

	}
	*/
		Serial.print("shot");
	delay(400);
}
