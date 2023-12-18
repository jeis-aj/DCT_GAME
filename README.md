# DCT GAME PROJECT

## Components

### Gun Game; Gun 
	* Arduino Pro Mini
	* Li-ion Battery Charging Module
	* LEDs indicator, 8 rounds (bullet), 1 Reloading Indicator
	* Push Switch 1 nos, as Gun Trigger
	* IR blasters  6 nos, parallel connection

### Gun Game; Game Board 
	* IR Receiver 9 nos
	* Wires ( Ethernet ) - for IR receiver
    + Arduino Mega 
    + Relay Module

#### SETUP 
	Plant LEDs on pillars along with ir reciever -->> ( Node )

	4 Wires to pillars 
		+ Gnd
		+ 5v Vcc 
		+ Relay control 
		+ IR receiver Signal

    2 Wires AC mains
        + LED pin 
        + To LED pin through Relay

#### WORK FLOW 

##### Gun Game Main Board
~~~mermaid
flowchart LR 
    start((start)) --> rand( Random Node Toggle )
    rand -----> |>>| if{node is active}
    if --> |NO|rand
    if -->|YES| tr{shoted} 
    tr --> |NO| rand
    tr --> |YES| inc[increment score]
    inc --> tim{is Timeout}
    tim --> |YES| stop((stop))
    tim --> |NO| rand 
~~~

##### Gun Game Gun Board
~~~mermaid
flowchart LR 
    start((start)) --> set[Set count \n zero] 
    set --> chk{ Check bullet \n Count }
    chk --> |Empty| rl[Reloading \n Delay 10 sec]
    stop((stop))
    rl --> stop
    chk --> |Have bullet| sht[Send IR \n Signal]
    sht --> dec[Decrement \n bullet ]
    dec ----> chk
~~~
