#include "motor.h"
#include "ultrasonic.h"

int main(void) {
	// Initialization
	gpioInit();
	timerInit();
	timerInit_sonic();
	initInterrupts();
	
	// Initialize servo motor to center position
	OCR1A = 3000;
	
	// timer/counter 2 initialization (for ultrasonic interrupt)
	TCCR2 |= (1 << CS22) || (1 << CS21) || (1 << CS20);
	TIMSK |= (1 << TOIE2);
	
	DDRD |= (1 << PORTD6);  // Set trigger pin as output
	DDRD &= ~(1 << PORTD7); // Set echo pin as input
	
	while (1) {
		
	}
}