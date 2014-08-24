#ifndef __eye_controls_h__
#define __eye_controls_h__



// 0 -- forward, 1 -- right, 2 -- left

void set_look_direction(){
	switch(current_car_state){
		case 'S':
		case 'F':
		case 'B':
			look_direction = 0;
			break;
		case 'L':
		case 'G':
		case 'H':
			look_direction = 2;
			break;
		case 'R':
		case 'I':
		case 'J':
			look_direction = 1;
			break;
		default:
			look_direction = 0;
			break;
	}
	
	eye_look_direction(eye_location, look_direction);
}

#endif
