#ifndef __movement_controls_h__
#define __movement_controls_h__

//for now left wheel B0 = forward B1 = back
// right B2 = forward b3 = back


//set max car speed***********
double max_car_speed = 145;


void set_car_speed(){
	switch(button_press){
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
}


void set_car_movement(){
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
		default:
			//forward
			PORTB = SetBit(PORTB, 0, 0);
			PORTB = SetBit(PORTB, 1, 0);
			PORTB = SetBit(PORTB, 2, 0);
			PORTB = SetBit(PORTB, 3, 0);
			break;
	}
}

#endif
