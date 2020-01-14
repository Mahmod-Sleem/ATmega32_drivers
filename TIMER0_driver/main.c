#include <avr/io.h>

#include <avr/interrupt.h>


volatile uint8_t count;

int main (void)

{

DDRD |= (1<<6); //PD6 as output

TCNT0 = 0;
OCR0 = 250;
count = 0;

TCCR0 |= (1<<CS02) | (1<<CS00) |(1<<WGM01); // PRESCALER 1024

TIMSK = (1<<OCIE0);

sei();

while(1)  {}

}



ISR (TIMER0_COMP_vect)

{
PORTD ^= (1<<6);


}
