based on Atmel attiny20

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

TM2637-based display (4x7 segment clock face)

