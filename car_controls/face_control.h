#ifndef __face_h__
#define __face_h__

#include "io.h"

//make sure to call LCD_init_g();

void draw_image(unsigned char i, unsigned char size){
	size = size + i;
	for(; i< size; ++i){
		LCD_WriteData(i);
	}
}


//takes in value of where to put the eye and the direction it is looking 0 -- straight 1-- right 2-- left
//left eye at 6 and right eye at 13
void eye_look_direction(unsigned char i, unsigned char direction){
	program_consecutive_characters(top_eye, 0, eye_size);
	LCD_Cursor(i);
	draw_image(0, eye_size);
	LCD_Cursor(i+7);
	draw_image(0, eye_size);
	
	if(direction == 0)
		program_consecutive_characters(look_straight_eye, 3, eye_size);
		
	else if(direction == 1)
		program_consecutive_characters(look_right_eye, 3, eye_size);
		
	else{
		program_consecutive_characters(look_left_eye, 3, eye_size);
	}
	
	LCD_Cursor(i+20);
	draw_image(3, eye_size);
	LCD_Cursor(i+27);
	draw_image(3, eye_size);
}


void blink_eye(unsigned char i){
	LCD_Cursor(i);
	LCD_WriteData('_');
	LCD_WriteData('_');
	LCD_WriteData('_');
	
	LCD_Cursor(i + 7);
	LCD_WriteData('_');
	LCD_WriteData('_');
	LCD_WriteData('_');
	
	LCD_Cursor(i + 20);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	
	LCD_Cursor(i + 27);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
}


void smile(){
	program_consecutive_characters(smile_img, 6, 2);
	
	LCD_Cursor(66);
	for(unsigned char i = 0; i < 10; ++i){
		LCD_WriteData('_');
	}
	
	LCD_Cursor(70);
	LCD_WriteData(2);
	LCD_WriteData(0);
	
	LCD_Cursor(65);
	LCD_WriteData(7);
	LCD_WriteData(6);
	LCD_Cursor(76);
	LCD_WriteData('/');
	LCD_Cursor(77);
	LCD_WriteData(0xDD);
}

#endif
