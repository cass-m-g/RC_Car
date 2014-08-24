#ifndef __movement_controls_h__
#define __movement_controls_h__

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
