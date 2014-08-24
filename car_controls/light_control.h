#ifndef __light_control_h__
#define __light_control_h__

//#include "global_vars.h"

//relys on input from button_press
enum front_lights_control{
	fl_on, fl_off
};

int front_lights_Tck(int state){
	switch(state){
		case fl_off:
		if(button_press == 'W'){
			//turn lights on ********
			PORTB = 0x02;
			state = fl_on;
		}
		break;
		case fl_on:
		if(button_press == 'w'){
			//turn lights off *********
			PORTB = 0x00;
			state = fl_off;
		}
		break;
		default:
		state = fl_off;
		
	}

	return state;
}

//relys on input from button_press
enum back_lights_control{
	bl_on, bl_off
};

int back_lights_Tck(int state){
	switch(state){
		case bl_off:
		if(button_press == 'U'){
			//turn lights on ********
			PORTB = 0x02;
			state = bl_on;
		}
		break;
		case bl_on:
		if(button_press == 'u'){
			//turn lights off *********
			PORTB = 0x00;
			state = bl_off;
		}
		break;
		default:
		state = bl_off;
		
	}
	
	return state;
}



#endif
