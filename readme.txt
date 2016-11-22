based on Atmel attiny20

BOM:
1. board
   $0.145
2. SoC processor (Atmel ATTINY20)
   $0.855
3. pin header (22 pins)
   $0.035
4. 1/4W 0.91R resistor (1)
   $0.015
5. battery holder
   $0.08
6. battery CR2032
   $0.165
7. 3-5mm throughole LEDs (9)
   $0.13
8. 20cm LED wires (18)
   $0.39
9. switch
   $0.10
10. 24AWG wire
   $0.065
---------
Total cost per menorah: $1.98

Tools
-----
10g solder paste
Soldering iron

Assembly instructions
---------------------
1) Solder processor(2) to PCB(1)
	i) Apply solder paste to PCB
	ii) place processor, aligning pin 1 to the top left (dot on PCB to dot on processor)	
	iii) Solder all legs of processor to PCB (or reflow)
	iv) visually inspect assembly for stray solder, weak connections, etc - clean up where necessary
2) Solder pins(3) to PCB(1)
	i) cut a row of 16 pins, solder to right side of PCB (pins 8-14, plus extra pins hanging off the bottom)
	ii) cut a row of 8 pins (7 minimum) to left side of PCB (pins 1-7 and optionally empty hole)

3) Solder resistor(4)
	i) Solder one leg of resistor(4) across bottom 9 pins of 16-pin header (right side of PCB)
	ii) Bend resistor 90 degrees so it lies across the bottom of the PCB
	iii) Solder second leg to extra pin (if in use)
	iv) Solder the remainder of the second leg to pin 14 (or pad connected to pin 14) - ground
4) Solder switch
	i) pick 2 legs on the "short" side of the switch
	ii) Solder one leg to a wire that connects to pin 5
	iii) Solder the other leg to a wire that connects to the extra pin (if used) or directly to ground

5) Solder battery holder
	i) 

Programming
-----------
1) Connect programmer to board according to pinout
2) Connect power to board (if programmer doesn't supply power)
3) sudo make flash

Wiring (dasa bitbang - MISO/MOSI share a line)
dasa             = serial port banging, reset=rts sck=dtr mosi=txd miso=cts

ATTINY20 pinout:

VCC    1   14 GND
CLK    2   13 PA0
MOSI   3   12 PA1
RESET  4   11 PA2
MISO   5   10 PA3
SCL    6    9 PA4
SS     7    8 PA5

reset: RTS -> PIN 4 (orange)
sck:   DTR -> PIN 2 (yellow)
mosi:  TXD -> grey (green)
miso:  CTS -> 1K (red) -> PIN 3 (grey)
+5V:   VDD -> PIN 1 (white)
-:     GND -> PIN 14 (black)

