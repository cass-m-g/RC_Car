#ifndef __movement_controls_h__
#define __movement_controls_h__

//for now left wheel B0 = forward B1 = back
// right B2 = forward b3 = back


//set max car speed***********
double max_car_speed = 145;

void set_button_presses(){
	button_press_movement = NULL;
	button_press_speed = NULL;
	
	switch(button_press){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'q':
			button_press_speed = button_press;
			break;
		
		case 'F':
		case 'B':
		case 'L':
		case 'G':
		case 'H':
		case 'R':
		case 'I':
		case 'J':
		case 'D':
		case 'S':
			button_press_movement = button_press;
			break;
	}
}


void set_car_speed(){
	switch(button_press_speed){
		case '0':
		
		break;
		case '1':
		
		break;
		case '2':
		
		break;
		case '3':
		
		break;
		case '4':
		
		break;
		case '5':
		
		break;
		case '6':
		
		break;
		case '7':
		
		break;
		case '8':
		
		break;
		case '9':
		
		break;
		case 'q':
		
		break;
	}
}


void set_car_stop(){
	
	PORTB = SetBit(PORTB, 0, 0);
	PORTB = SetBit(PORTB, 1, 0);
	PORTB = SetBit(PORTB, 2, 0);
	PORTB = SetBit(PORTB, 3, 0);
	
	//turn on break lights**********
	PORTA = SetBit(PORTA, 2, 1);
	PORTA = SetBit(PORTA, 3, 1);
}


void set_car_movement(){
	//turn off brake lights if the car just stops then the break lights will turn back on
	PORTA = SetBit(PORTA, 2, 0);
	PORTA = SetBit(PORTA, 3, 0);
	
	switch(current_car_state){
		case 'F':
		//forward
		PORTB = SetBit(PORTB, 0, 1);
		PORTB = SetBit(PORTB, 1, 0);
		PORTB = SetBit(PORTB, 2, 1);
		PORTB = SetBit(PORTB, 3, 0);
		
		break;
		case 'B':
		PORTB = SetBit(PORTB, 0, 0);
		PORTB = SetBit(PORTB, 1, 1);
		PORTB = SetBit(PORTB, 2, 0);
		PORTB = SetBit(PORTB, 3, 1);
		//backward
		break;
		case 'L':
		PORTB = SetBit(PORTB, 0, 0);
		PORTB = SetBit(PORTB, 1, 1);
		PORTB = SetBit(PORTB, 2, 1);
		PORTB = SetBit(PORTB, 3, 0);
		//left
		break;
		case 'G':
		PORTB = SetBit(PORTB, 0, 0);
		PORTB = SetBit(PORTB, 1, 1);
		PORTB = SetBit(PORTB, 2, 1);
		PORTB = SetBit(PORTB, 3, 0);
		//forward left
		break;
		case 'H':
		PORTB = SetBit(PORTB, 0, 1);
		PORTB = SetBit(PORTB, 1, 0);
		PORTB = SetBit(PORTB, 2, 0);
		PORTB = SetBit(PORTB, 3, 1);
		//back left
		break;
		case 'R':
		PORTB = SetBit(PORTB, 0, 1);
		PORTB = SetBit(PORTB, 1, 0);
		PORTB = SetBit(PORTB, 2, 0);
		PORTB = SetBit(PORTB, 3, 1);
		//right
		break;
		case 'I':
		PORTB = SetBit(PORTB, 0, 1);
		PORTB = SetBit(PORTB, 1, 0);
		PORTB = SetBit(PORTB, 2, 0);
		PORTB = SetBit(PORTB, 3, 1);
		//forward right
		break;
		case 'J':
		PORTB = SetBit(PORTB, 0, 0);
		PORTB = SetBit(PORTB, 1, 1);
		PORTB = SetBit(PORTB, 2, 1);
		PORTB = SetBit(PORTB, 3, 0);
		//back right
		break;
		case 'D':
		//stop all bluetooth disconected!!!
		
		set_car_stop();
		
		//manage emergency lights************
		//emergency lights will flash on and off (250 ms)
		//this can also be controlled by a button
		
		break;
		default:
		//stop
		set_car_stop();
		break;
	}
}

#endif
