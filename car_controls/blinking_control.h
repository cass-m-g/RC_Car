#ifndef __blink_control_h__
#define __blink_control_h__

enum blink_control{
	blink_wait, blink
};

unsigned char blink_time = 0;

int blink_control_Tck(int state){
	switch(state){
		case blink_wait:
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
		state = blink_wait;
		break;
		default:
		state = blink_wait;
	}
	
	return state;
}

#endif
