#include "my_func.h"

void call_command(uint8_t char_buff[256], struct file filesys[FILES]){
	uint8_t command[16] = {0};
	uint8_t i;
	for(i=0;i<16;++i){
		if(char_buff[i] == ' ' || char_buff[i] == 0){
			break;
		}else{
			command[i] = char_buff[i];
		}
	}
	if(strcmp(command,"echo") == 0){
		while(char_buff[i] != 0){
			i++;
			stdio_c(char_buff[i]);
		}
		stdio_c('\n');
	}else if(strcmp(command,"touch")==0){
		i++;
		touch(char_buff, i, filesys);
	}else if(strcmp(command,"ls")==0){
		ls(filesys);
	}else if(strcmp(command,"rm")==0){
		i++;
		rm(char_buff, i, filesys);
	}else if(strcmp(command,"help")==0){
		help();
	}else if(strcmp(command,"?")==0){
		help();
	}else if(strcmp(command,"write")==0){
		i++;
		uint8_t index;
		index = find(char_buff, i, filesys);
		write(filesys, index);
	}else if(strcmp(command,"cat")==0){
		i++;
		uint8_t index;
		index = find(char_buff, i, filesys);
		cat(filesys, index);
	}else if(strcmp(command,"find")==0){
		i++;
		uint8_t index;
		index= find(char_buff, i, filesys);
		stdio_write(filesys[index].name);
		stdio_write(" \n");
	}else if(strcmp(char_buff,"halt")==0){
		powr_toggle(0);
	}else if(strcmp(char_buff,"clear")==0){
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

}
void animate_splash(void){
	uint16_t i;
	for(i=0; i<800; i++){
		powr_toggle(45);
		tft_fill_area((get_rnd() & 0x1ff), (get_rnd() & 0xff), (get_rnd() & 0x09), (get_rnd() & 0x09), (get_rnd()<<16 | get_rnd()));
		uint8_t col = (get_rnd() & 0x01);
		if(col == 1){
			screen_splash(0);
		}else{
			screen_splash(0xffffffff);
		}
	}
	// sound_play_notes(0, 0, 60, 1000);
	// sound_play_notes(0, 0, 67, 1000);
	// sound_play_notes(0, 0, 72, 1050);
	// sound_play_notes(63, 72, 75, 200);
	// sound_play_notes(64, 72, 76, 1000);
	tft_fill_area(0,0,320,240,0xffffffff);
	screen_splash(0);
	wait_ms(250);
	tft_fill_area(0,0,320,240,0);
	screen_splash(0xffffffff);
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

void touch(uint8_t char_buff[256], uint8_t i, struct file filesys[FILES]){
	uint8_t p, w = 0, j, count;

	for(p=0; p<FILES; p++){
		count = 0;
		for(j=0; j<16; j++){
			if(filesys[p].name[j] == char_buff[i+j]){
				count++;
			}
		}
	}
	if(count!=16 || filesys[0].name[0]==0){
		for(p=0; p<FILES; p++){
			if(filesys[p].name[0] == 0){
				while(char_buff[i+w] != 0){
					filesys[p].name[w] = char_buff[i+w];
					w++;
				}
				break;
			}
		}
	}
}
void ls(struct file filesys[FILES]){
	uint8_t w;
	for(w=0; w<FILES; w++){
		if(filesys[w].name[0] != 0){
			stdio_write(filesys[w].name);
			stdio_c('\n');
		}
	}
}
void rm(uint8_t char_buff[256], uint8_t i, struct file filesys[FILES]){
	uint8_t p, j, count;
	for(p=0; p<FILES; p++){
		count = 0;
		for(j=0; j<16; j++){
			if(filesys[p].name[j] == char_buff[i+j]){
				count++;
			}
		}
		if(count==16){
			filesys[p].name[0] = 0;
		}
	}
}
uint8_t find(uint8_t char_buff[256], uint8_t i, struct file filesys[FILES]){
	uint8_t p, j, count;
	for(p=0; p<FILES; p++){
		count = 0;
		for(j=0; j<16; j++){
			if(filesys[p].name[j] == char_buff[i+j]){
				count++;
			}
		}
		if(count==16){
			return p;
		}
	}
	return 255;
}
void write(struct file filesys[FILES], uint8_t index){
	uint8_t charbs = 0, statsget = 0, singchar, data_buff[256] = {0};
	do{
		powr_toggle(45);
		statsget = stdio_get(&charbs);
		if (statsget!=0){
			if(charbs!=K_ENT){
				data_buff[singchar] = charbs;
				if(singchar >= 0 && charbs!=BACKSPACE){
					stdio_c(charbs);
					singchar++;
				}else if(singchar > 0 && charbs==BACKSPACE){
					stdio_c(charbs);
					singchar--;
				}
			}else{
				stdio_c('\n');
			}
		}
	}while(charbs!=K_ENT);
	uint8_t hsh =0;
	while(data_buff[hsh] != 0){
		filesys[index].data[hsh] = data_buff[hsh];
		hsh++;
	}
}
void cat(struct file filesys[FILES], uint8_t index){
	uint8_t hsh =0;
	while(filesys[index].data[hsh] != 0){
		stdio_c(filesys[index].data[hsh]);
		hsh++;
	}
	stdio_c('\n');
}
void help(void){
	stdio_write("\n");
	stdio_write("clear - clears the screen\n");
	stdio_write("echo  - prints to the screen\n");
	stdio_write("rm    - removes a file\n");
	stdio_write("touch - creates a new file\n");
	stdio_write("ls    - list all files\n");
	stdio_write("write - write to file\n");
	stdio_write("find  - finds a file\n");
	stdio_write("cat   - prints a file\n");
	stdio_write("help  - displays this help message\n");
	stdio_write("\n");
}









