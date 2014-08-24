#ifndef __movement_controls_h__
#define __movement_controls_h__

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


void set_car_movement(){
	switch(current_car_state){
		case 'F':
			//forward
			break;
		case 'B':
			//backward
			break;
		case 'L':
			//left
			break;
		case 'G':
			//forward left
			break;
		case 'H':
			//back left
			break;
		case 'R':
			//right
			break;
		case 'I':
			//forward right 
			break;
		case 'J':
			//back right
			break;
		default:
			//forward
			break;
	}
}

#endif
