TOOLPATH=/usr/local/avr/bin/
CC=avr-gcc 
CFLAGS=-mmcu=$(DEVICE) -Wall -Os -DF_CPU=$(CLOCK)
AVRDUDE=avrdude
CLOCK=1000000
DEVICE=attiny20
DELAY=10

.PHONY: tags

all: menorah.hex

menorah.elf: main.c
	$(TOOLPATH)$(CC) $(CFLAGS) main.c -o menorah.elf

%.hex: %.elf
	$(TOOLPATH)avr-objcopy -j .text -j .data -O ihex $< $@
	# $(TOOLPATH)avr-size --format=avr --mcu=$(DEVICE) $<.elf

flash:
	$(AVRDUDE) -U flash:w:menorah.hex:i -c dasaftdi -p t20 -P /dev/ttyUSB0 -i $(DELAY)

tags:
	ctags -R -f tags * /usr/local/avr/avr/include/*
