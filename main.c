#include <avr/io.h>
#include <util/delay.h> // for _delay_ms
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define MAX_NIGHT 8

static volatile int night=MAX_NIGHT;
static volatile int button=0;

ISR(INT0_vect)
{
   _delay_ms(10);

   if ((button == 0) && !(PINB & 1<<PINB2))
   {
      // got a button push, increment night counter, set correct number of lights
      button = 1;
      night--;
      if (night < 0) night=MAX_NIGHT;
      PORTA = 0xFF >> night;
   }
   else if ((button == 1) && (PINB & 1<<PINB2))
   {
      button = 0;
   }
}

int main(void)
{
   DDRA = 0xFF;      // set all 8 'A' ports as output
   DDRB = 1<<DDB1;   // set all port B as input, except B1
   PUEA = 0;         // shut off pull-up for all 8 'A' ports
   PUEB = 1<<PUEB2;  // turn on pull-up for B2
   PORTB = 1<< PORTB1; // shamash should always be on

   MCUCR = 1<<SM1 | 1<<SE; //generate INT0 on falling edge
   GIMSK = 1; // allow INT0 to be generated
   sei(); // enable interrupts

   while (1)
   {
      sleep_cpu();
   }

   return 0;
}
