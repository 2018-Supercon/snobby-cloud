#include "my_func.h"

void call_command(uint8_t char_buff[256]){
	if(strcmp(char_buff,"clear")==0){
		video_clrscr();
	}else if(char_buff[0]==0){
		
	}else if(strcmp(char_buff,"kelp")==0){
		stdio_write("Who lives in a pineapple under the sea?\n");
	}else{
		switch((char_buff[0] + get_rnd()) & 0x1f){
			case 0:
				stdio_write("Have you been into Branko's rakija?\n");
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
			case 8:
				stdio_write("Prove you're human: 0b101010\n");
				break;
			case 9:
				stdio_write("I don't think that mean what you think it means.\n");
				break;
			case 10:
				stdio_write("Want to play a game?\n");
				break;
			case 11:
				stdio_write("How do I get 30 extra lives?\n");
				break;
			case 12:
				stdio_write("Maybe you should RTFM\n");
				break;
			case 13:
				stdio_write("Erm... It's supposed to do that\n");
				break;
			case 14:
				stdio_write("Too many errors on one line (make fewer)\n");
				break;
			case 15:
				stdio_write("You are in a maze of twisty compiler features, all different\n");
				break;
			case 16:
				stdio_write("Parse error: unexpected idoiot at the keyboard\n");
				break;
			case 17:
				stdio_write("Program Lost -- Sorry.\n");
				break;
			case 18:
				stdio_write("I find your lack of faith disturbing\n");
				break;
			case 19:
				stdio_write("There are people who know what they're doing, then there's you\n");
				break;
			case 20:
				stdio_write("My brain just exploded.\n");
				break;
			case 21:
				stdio_write("You can't just start making up commands\n");
				break;
			case 22:
				stdio_write("Try restarting shockwave\n");
				break;
			case 23:
				stdio_write("That really grinds my ALU\n");
				break;
			case 24:
				stdio_write("Erq ureevat\n");
				break;
			case 25:
				stdio_write("I'm drawing a blank\n");
				break;
			case 26:
				stdio_write("Make your own sandwich\n");
				break;
			case 27:
				stdio_write("No Thanks...\n");
				break;
			case 28:
				stdio_write("I call myself SuperBoss\n");
				break;
			case 29:
				stdio_write("You are as useless as a white crayon\n");
				break;
			case 30:
				stdio_write("See a doctor. You may not be fit to work a computer\n");
				break;
			case 31:
				stdio_write("No. Just No\n");
				break;
		};
	}
<<<<<<< HEAD
	
	uint8_t command[7] = {'\0'};
	uint8_t i;
	for(i=0;i<7;++i){
		if(char_buff[i] == ' '){
			break;
		}else{
			command[i] = char_buff[i];
		}
	}

	if(strcmp(command,"echo") == 0){
		while(char_buff[i] != '\0'){
			stdio_c(char_buff[i]);
		}
	}else if(strcmp(command,"mkdir")){

	}else if(strcmp(command,"rmdir")){

	}else if(strcmp(command,"pwd")){

	}else if(strcmp(command,"cd")){

	}else if(strcmp(command,"rm")){

	}else if(strcmp(comand,"mv")){

	}else if(strcmp(command,"ls")){

	}else if(strcmp(command,"cp")){

	}else if(strcmp(command,"cat")){

	}else if(strcmp(command,"man")){

	}
=======
>>>>>>> af37dd4eea68f4cbb07117d069c90b63d06bf571
}

void animate_splash(void){
	wait_ms(750);
	uint16_t i;
	for(i=0; i<800; i++){
		tft_fill_area((get_rnd() & 0x1ff), (get_rnd() & 0xff), (get_rnd() & 0x09), (get_rnd() & 0x09), (get_rnd()<<16 | get_rnd()));
		uint8_t col = (get_rnd() & 0x01);
		if(col == 1){
			screen_splash(0);
		}else{
			screen_splash(0xffffffff);
		}
		wait_ms((get_rnd() & 0x01));
	}
	tft_fill_area(0,0,320,240,0xffffffff);
	screen_splash(0);
	wait_ms(250);
	tft_fill_area(0,0,320,240,0);
	screen_splash(0xffffffff);
	// sound_play_notes(72, 75, 79, 75);
	// sound_play_notes(72, 77, 80, 75);
	// sound_play_notes(71, 74, 79, 75);
	tft_fill_area(0,0,320,240,0x000000);
}



void screen_splash(uint32_t color){
	uint8_t size = 4, offseth = 100, offsetw = 120;
	tft_fill_area(offsetw+(size*3), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*5), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*9), offseth+(size*1), size, size, color);

	tft_fill_area(offsetw+(size*2), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*3), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*9), offseth+(size*2), size, size, color);

	tft_fill_area(offsetw+(size*1), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*2), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*3), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*9), offseth+(size*3), size, size, color);

	tft_fill_area(offsetw+(size*1), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*2), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*3), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*5), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*9), offseth+(size*4), size, size, color);

	tft_fill_area(offsetw+(size*2), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*3), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*5), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*5), size, size, color);

	tft_fill_area(offsetw+(size*3), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*5), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*6), size, size, color);
	
	tft_fill_area(offsetw+(size*1), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*5), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*9), offseth+(size*7), size, size, color);

	tft_fill_area(offsetw+(size*1), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*2), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*9), offseth+(size*8), size, size, color);

	tft_fill_area(offsetw+(size*1), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*2), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*3), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*8), offseth+(size*9), size, size, color);

	tft_fill_area(offsetw+(size*1), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*2), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*3), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*4), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*5), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*6), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*7), offseth+(size*10), size, size, color);





	tft_fill_area(offsetw+(size*12), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*14), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*15), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*16), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*17), offseth+(size*1), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*1), size, size, color);

	tft_fill_area(offsetw+(size*11), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*16), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*17), offseth+(size*2), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*2), size, size, color);

	tft_fill_area(offsetw+(size*10), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*11), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*17), offseth+(size*3), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*3), size, size, color);

	tft_fill_area(offsetw+(size*10), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*11), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*4), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*4), size, size, color);

	tft_fill_area(offsetw+(size*10), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*11), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*5), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*5), size, size, color);

	tft_fill_area(offsetw+(size*10), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*11), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*6), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*6), size, size, color);

	tft_fill_area(offsetw+(size*10), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*11), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*7), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*7), size, size, color);

	tft_fill_area(offsetw+(size*10), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*11), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*17), offseth+(size*8), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*8), size, size, color);

	tft_fill_area(offsetw+(size*11), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*12), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*16), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*17), offseth+(size*9), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*9), size, size, color);

	tft_fill_area(offsetw+(size*12), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*13), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*14), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*15), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*16), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*17), offseth+(size*10), size, size, color);
	tft_fill_area(offsetw+(size*18), offseth+(size*10), size, size, color);
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