#ifndef __movement_controls_h__
#define __movement_controls_h__

//for now left wheel B0 = forward B1 = back
// right B2 = forward b3 = back

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
			set_car_speed();
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


//0 --- fastest
//255 -- stopped

void set_car_speed(){
	switch(button_press_speed){
		case '0':
			car_speed = 140;
		break;
		case '1':
		car_speed = 120;
		
		break;
		case '2':
		car_speed = 100;
		
		break;
		case '3':
		car_speed = 80;
		
		break;
		case '4':
		car_speed = 60;
		
		break;
		case '5':
		car_speed = 50;
		
		break;
		case '6':
		car_speed = 40;
		
		break;
		case '7':
		car_speed = 30;
		
		break;
		case '8':
		car_speed = 20;
		
		break;
		case '9':
		car_speed = 10;
		
		break;
		case 'q':
		car_speed = 0;
		
		break;
	}
}


void set_car_stop(){
	
	M_off();
	
	//turn on break lights**********
	PORTA = SetBit(PORTA, 2, 1);
	PORTD = SetBit(PORTD, 5, 1);
}


void set_car_movement(){
	//turn off brake lights if the car just stops then the break lights will turn back on
	PORTA = SetBit(PORTA, 2, 0);
	PORTD = SetBit(PORTD, 5, 0);
	
	switch(current_car_state){
		case 'F':
			//forward
			M1_forward(car_speed);
			M2_forward(car_speed);
		
			break;
		case 'B':
			M1_reverse(car_speed);
			M2_reverse(car_speed);
		
			//backward
			break;
		case 'L':
			//left
			M1_reverse(car_speed);
			M2_forward(car_speed);
			break;
		case 'G':
			//forward left
			M1_reverse((255- car_speed)/2 + car_speed);
			M2_forward(car_speed);
			break;
		case 'H':
			//back left
			M1_forward((255- car_speed)/2 + car_speed);
			M2_reverse(car_speed);
			break;
		case 'R':
			//right
			M1_forward(car_speed);
			M2_reverse(car_speed);
			break;
		case 'I':
			//forward right
			M1_forward(car_speed);
			M2_reverse((255- car_speed)/2 + car_speed);
			break;
		case 'J':
			//back right
			M1_reverse(car_speed);
			M2_forward((255- car_speed)/2 + car_speed);
			break;
		case 'D':
			//stop all bluetooth disconected!!!
		
			set_car_stop();
		
			break;	
		default:
			//stop
			set_car_stop();
			break;
	}
}

#endif
