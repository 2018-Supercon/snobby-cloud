#include <xc.h>
#include "badge.h"
#include "hw.h"
#include "disp.h"
#include "my_func.h"

uint8_t char_out, get_stat, single_char;


int16_t main(void){
	hw_init();
	badge_init();
	
	boot_animation();
	
	
	stdio_write("Welcome to Snobby Cloud!\n");
	do{
		uint8_t char_buff[256] = {0};
		stdio_write("> ");
		single_char = 0;
		char_out = 0;
		do{
			get_stat = stdio_get(&char_out);
			if (get_stat!=0){
				if(char_out!=K_ENT){
					char_buff[single_char] = char_out;
				}
				if(single_char >= 0 && char_out!=BACKSPACE){
					stdio_c(char_out);
					single_char++;
				}else if(single_char > 0 && char_out==BACKSPACE){
					stdio_c(char_out);
					single_char--;
				}
			}
		}while(char_out!=K_ENT);
		// int i;
		// for(i=0; i<single_char; i++){
			// stdio_c(char_buff[i]);
		// }
		// stdio_c('\n');
		
		
		call_command(char_buff);
		
		
	}while(1);
}

// 