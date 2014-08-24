/* Partner 1 Name & E-mail: Cassandra Garner cgarn002@ucr.edu
 * Lab Section: 221
 * Assignment: Personal Project
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */

#include <avr/io.h>
#include "global_vars.h"
#include "bit.h"
#include "timer.h"
#include "face_characters.h"
#include "face_conrol.h"
#include "usart_atmega1284.h"
#include <avr/interrupt.h>
#include "light_control.h"
#include "blinking_control.h"

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



/*  Bluetooth control commands:
*		Forward -- F
*		Back	-- B
*		Left	-- L
*		Right	-- R
*		Forward Left	-- G
*		Forward Right	-- I
*		Backward Left	-- H
*		Backward Right	-- J
*		Stop	-- S
*		Front Lights On	-- W (upper case)
*		Front Lights Off-- w (lower case)
*		Back Lights On	-- U (upr)
*		Back Lights Off -- u (lwr)
*		Horn On		-- V (upr)
*		Horn Off	-- v (lwr)
*		Extra On	-- X (upr)
*		Extra Off	-- x (lwr)
*		Speed 0		-- 0 (zero)
*		Speed 10	-- 1
*		...
*		Speed 90	-- 9
*		Speed 100	-- q
*		Stop All	-- D
*/



//This controls the read from the bluetooth device.
//This Tck function must be the first in the for loop
//All Tck functions that relly on the information stored in button_press must run on the same period

enum bluetooth_control{
	b_wait, b_data
	};
	
int bluetooth_Tck(int state){
	switch(state){
		case b_wait:
			if(USART_HasReceived()){
				button_press = USART_Receive();
				state = b_data;
			}
			break;
		case b_data:
			button_press = NULL;
			state = b_wait;
			break;
		default:
			state = b_wait;
			break;
	}
	return state;
}

int main(void)
{
	DDRC = 0xFF; PORTC = 0x00; 
	DDRD = 0xFE; PORTD = 0x01;
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	
	LCD_init();
	USART_Init(9600);
	
	LCD_WriteCommand(0x0c);
	LCD_ClearScreen();
	smile();
	
	
	unsigned long int GCD = 25;
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
	
	PORTB = 0x00;
	
	while(1) {
		
		/*
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
		*/
		while(!TimerFlag);
		TimerFlag = 0;
		
	}
	
}
