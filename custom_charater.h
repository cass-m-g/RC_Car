#ifndef __custom_character_h__
#define __custom_character_h__

#include "io.c"
#include "binary_to_hex.h"

/*pos represents the character to be stored at
 * arr stores the custom charecters must be of size 8
 */
void create_character(unsigned char arr[], unsigned char pos){
	LCD_WriteCommand(0x40 + 8*pos);
	
	for(unsigned char i = 0; i<8; ++i){
		LCD_WriteData(arr[i]);
	}
	
	LCD_WriteCommand(0x02);
}

/*
 * takes in 2d arr and its size of the consecutive custom characters
 */
void program_consecutive_characters(unsigned char arr[][8], unsigned char startpos, unsigned long size){
	for(unsigned long i = 0; i < size; ++i){
		create_character(arr[i], startpos+i);
	}
}

#endif
