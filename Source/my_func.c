#include "my_func.h"

void call_command(uint8_t char_buff[256]){
	if(strcmp(char_buff,"clear")==0){
		video_clrscr();
	}else{
		switch((char_buff[0] + get_rnd()) & 0x07){
			case 0:
				stdio_write("Make your own sandwich\n");
				break;
			case 1:
				stdio_write("Existence itself is not a hack\n");
				break;
			case 2:
				stdio_write("101010 *IS* the answer\n");
				break;
			case 3:
				stdio_write("Hackers don't need manuals\n");
				break;
			case 4:
				stdio_write("Han shot first\n");
				break;
			case 5:
				stdio_write("You're in a room filled with hackers\n");
				break;
			case 6:
				stdio_write("I am afraid I can't do that Dave\n");
				break;
			case 7:
				stdio_write("Who do you think you are?! I AM!!!!!\n");
				break;
		};
	}
	
	
	
	

	
	
	
	
}


/* void powr_toggle(){
	volatile int8_t brk_key,stdio_src;
	if (K_PWR==0 && LCD_PWR == 0){
		while(K_PWR==0){
			wait_ms(100);
		}
		hw_sleep();
		wait_ms(30);
		while (K_PWR==0){
			wait_ms(300);	
		}
	}
	// if(K_PWR==0 && LCD_PWR == 1){
		// while(K_PWR==0){
			// wait_ms(100);
		// }
		// hw_init();
		// badge_init();
		// wait_ms(30);
		// while (K_PWR==0){
			// wait_ms(300);	
		// }
	// }
	static uint8_t brk_is_pressed;
	if (KEY_BRK==0){
		if (brk_is_pressed==9){
			if ((K_SHIFTL==0)&(K_SHIFTR==0)){
				serial_flush();
				if (stdio_src == STDIO_TTY1){
					stdio_src = STDIO_LOCAL;
				}else{
					stdio_src = STDIO_TTY1;
				}
			}else{
				brk_key = 1;
			}
		}
		if (brk_is_pressed<10){
			brk_is_pressed++;
		}
	}else{
		brk_is_pressed = 0;
	}
} */