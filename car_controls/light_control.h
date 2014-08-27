#ifndef __light_control_h__
#define __light_control_h__

//#include "global_vars.h"
//these controls rely on bluetooth thus have to be the same period

//relys on input from button_press
enum front_lights_control{
	fl_on, fl_off
};

int front_lights_Tck(int state){
	switch(state){
		case fl_off:
		if(button_press == 'W'){
			//turn lights on ********
			PORTA = SetBit(PORTA, 0, 1);
			PORTA = SetBit(PORTA, 1, 1);
			state = fl_on;
		}
		break;
		case fl_on:
		if(button_press == 'w'){
			//turn lights off *********
			PORTA = SetBit(PORTA, 0, 0);
			PORTA = SetBit(PORTA, 1, 0);
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
			//PORTB = SetBit(PORTB, 2, 1);
			state = bl_on;
		}
		break;
		case bl_on:
		if(button_press == 'u'){
			//turn lights off *********
			//PORTB = SetBit(PORTB, 2, 0);
			state = bl_off;
		}
		break;
		default:
		state = bl_off;
		
	}
	
	return state;
}



#endif
