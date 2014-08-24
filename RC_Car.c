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
#include "eye_controls.h"
#include "movement_controls.h"


//Declaration of global_vars:


unsigned char button_press = 0;
// 0 -- forward, 1 -- right, 2 -- left
unsigned char look_direction = 0;
unsigned char eye_location = 6;
unsigned char current_car_state = 'S';
// declare car_speed here *********
double car_speed = 0;

//end of global_vars

typedef struct _task {
	/*Tasks should have members that include: state, period,
		a measurement of elapsed time, and a function pointer.*/
	signed char state; //Task's current state
	unsigned long int period; //Task period
	unsigned long int elapsedTime; //Time elapsed since last task tick
	int (*TickFct)(int); //Task tick function
} task;

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
				set_car_speed();
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



enum car_move_control{
	car_stop, car_go
};

int car_move_Tck(int state){
	switch(state){
		case car_stop:
			if(button_press != 'S' && button_press != NULL){
				state = car_go;
				current_car_state = button_press;
				
				//change look direction
				set_look_direction();
			}
			break;
			
		case car_go:
			if(button_press == 'S'){
				state = car_stop;
				current_car_state = button_press;
				
				//change look direction
				set_look_direction();
			}
			else if(button_press != current_car_state && button_press != NULL){
				current_car_state = button_press;
				
				//change look direction
				set_look_direction();		
			}
			break;
		default:
			state = car_stop;
			current_car_state = 'S';
			break;		
	}
	
	switch(state){
		case car_stop:
			//stop car***********
			break;
		case car_go:
			//make car go*************
			set_car_movement();
			break;			
	}
	
	return state;
}

/*
enum speed_control{
	
};

int speed_Tck(int state){
	switch(state){
		
	}
	
	return state;
};
*/
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
	unsigned long int task_bluetooth_Period = 25, task_eye_blink_period = 150;
	
	static task task_bluetooth, task_eye_blink, task_front_lights, task_back_lights, task_car_movement;
	
	task *tasks[] = {&task_bluetooth, &task_eye_blink, &task_front_lights, &task_back_lights, &task_car_movement};
		
	task_bluetooth.state = b_wait;
	task_bluetooth.period = task_bluetooth_Period/GCD;
	task_bluetooth.elapsedTime = task_bluetooth_Period/GCD;
	task_bluetooth.TickFct = &bluetooth_Tck;
		
	task_eye_blink.state = blink_wait;
	task_eye_blink.period = task_eye_blink_period/GCD;
	task_eye_blink.elapsedTime = task_eye_blink_period/GCD;
	task_eye_blink.TickFct = &blink_control_Tck;
	
	task_front_lights.state = fl_off;
	task_front_lights.period = task_bluetooth_Period/GCD;
	task_front_lights.elapsedTime = task_bluetooth_Period/GCD;
	task_front_lights.TickFct = &front_lights_Tck;
	
	task_back_lights.state = bl_off;
	task_back_lights.period = task_bluetooth_Period/GCD;
	task_back_lights.elapsedTime = task_bluetooth_Period/GCD;
	task_back_lights.TickFct = &back_lights_Tck;
	
	task_car_movement.state = car_stop;
	task_car_movement.period = task_bluetooth_Period/GCD;
	task_car_movement.elapsedTime = task_bluetooth_Period/GCD;
	task_car_movement.TickFct = &car_move_Tck;
	
	TimerSet(GCD);
	TimerOn();
	
	unsigned short i;
	const unsigned short numTasks = 5;//sizeof(tasks)/sizeof(task*);
	
	eye_look_direction(6, 0);
	
	PORTB = 0x00;
	
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
