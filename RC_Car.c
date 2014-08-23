/* Partner 1 Name & E-mail: Cassandra Garner cgarn002@ucr.edu
 * Lab Section: 221
 * Assignment: Personal Project
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */

#include <avr/io.h>
#include "bit.h"
#include "timer.h"
#include "face_characters.h"
#include "face_conrol.h"
#include <avr/interrupt.h>

typedef struct _task {
	/*Tasks should have members that include: state, period,
		a measurement of elapsed time, and a function pointer.*/
	signed char state; //Task's current state
	unsigned long int period; //Task period
	unsigned long int elapsedTime; //Time elapsed since last task tick
	int (*TickFct)(int); //Task tick function
} task;

enum eye_control{
	left, right, straight
	};

// 0 -- forward, 1 -- right, 2 -- left
unsigned char look_direction = 0;
unsigned char eye_location = 6;

/* When turning right eyes turn this way and so on
		this task can be deleted when have the turning mechanism (that can control eyemovement)
*/
int eye_control_Tck(int state){
	switch(state){
		case straight:
			look_direction = 1;
			eye_look_direction(eye_location, look_direction);
			state = right;
			break;
		case left:
			look_direction = 0;
			eye_look_direction(eye_location, look_direction);
			state = straight;
			break;
		case right:
			look_direction = 2;
			eye_look_direction(eye_location, look_direction);
			state = left;
			break;
		default:
			state = left;
			
	}
	
	switch(state){
		case left:
			//eye_look_left(6);
			//look_direction = 2;
			break;
		case right:
			//eye_look_right(6);
			//look_direction = 1;
			break;
	}
	
	return state;
}

enum blink_control{
	wait, blink
	};

unsigned char blink_time = 0;

int blink_control_Tck(int state){
	switch(state){
		case wait:
			if (blink_time >= 35){
				state = blink;
				blink_eye(eye_location);
				blink_time = 0;
			}
			else{
				++blink_time;
			}
			break;
		case blink:
			eye_look_direction(eye_location, look_direction);
			state = wait;
			break;
		default:
			state = wait;
	}
	
	return state;
}

int main(void)
{
	DDRC = 0xFF; PORTC = 0x00; 
	DDRD = 0xFF; PORTD = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	
	LCD_init();
	
	LCD_WriteCommand(0x0c);
	LCD_ClearScreen();
	smile();
	
	
	unsigned long int GCD = 150;
	unsigned long int task_eye_Period = 1000, task_eye_blink_period = 150;
	
	static task task_eye, task_eye_blink;
	
	task *tasks[] = {&task_eye, &task_eye_blink};
	
	task_eye.state = right;
	task_eye.period = task_eye_Period/GCD;
	task_eye.elapsedTime = task_eye_Period/GCD;
	task_eye.TickFct = &eye_control_Tck;
	
	task_eye_blink.state = wait;
	task_eye_blink.period = task_eye_blink_period/GCD;
	task_eye_blink.elapsedTime = task_eye_blink_period/GCD;
	task_eye_blink.TickFct = &blink_control_Tck;
	
	TimerSet(GCD);
	TimerOn();
	
	unsigned short i;
	const unsigned short numTasks = 2;//sizeof(tasks)/sizeof(task*);
	
	eye_look_direction(6, 0);
	
	
	
	while(1) {
		
		for ( i = 0; i < numTasks; i++ ) {
			// Task is ready to tick
			if ( tasks[i]->elapsedTime >= tasks[i]->period ) {
				// Setting next state for task
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				// Reset the elapsed time for next tick.
				tasks[i]->elapsedTime = 0;
				
			}
			tasks[i]->elapsedTime += 1;
		}
		
		while(!TimerFlag);
		TimerFlag = 0;
		
	}
	
}
