# DCT GAME PROJECT



## Components

### Gun 
	* Arduino Pro Mini
	* Li-ion Battery
	* LED s
	* Push Switch 4 nos
	* IR blasters  6 nos 

### Panel 
	* IR Receiver 18 nos
	* Wires ( Ethernet ) - for IR receiver



#### work flow 
	plant leds in pillars along with ir reciever
	3 wires to pillars
		+ gnd
		+ relay control 
		+ ir receiver


~~~mermaid
flowchart TD
    A[Christmas] -->|Get money| B(Go shopping)
    B --> C{Let me think}
    C -->|One| D[Laptop]
    C -->|Two| E[iPhone]
    C -->|Three| F[fa:fa-car Car]

~~~
flowchart TD

    start(start)--> rn{random  0-9 }
    rn --> |led1|led1(light LED 1)
    rn --> |led2|led2(light LED 2)
    rn --> |led3|led3(light LED 3)
    rn --> |led4|led4(light LED 4)
    rn --> |led5|led5(light LED 5)
    rn --> |led6|led6(light LED 6)
    rn --> |led7|led7(light LED 7)
    rn --> |led8|led8(light LED 8)
    rn --> |led9|led9(light LED 9)

		led1  --> offled( Turn off all LED ) 
		led2  --> offled( Turn off all LED )  
		led3  --> offled( Turn off all LED )
		led4  --> offled( Turn off all LED )
		led5  --> offled( Turn off all LED )
		led6  --> offled( Turn off all LED )
		led7  --> offled( Turn off all LED )
		led8  --> offled( Turn off all LED )
		led9  --> offled( Turn off all LED )

	e(stop);
	

	create class node{
		led out 
		sensor in 
		fn ( arg , (*fn) )
	}
