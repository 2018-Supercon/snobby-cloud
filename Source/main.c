#include <xc.h>
#include "badge.h"
#include "hw.h"

uint8_t char_out;

int16_t main(void){
	hw_init();
	
	
	
	badge_init();
	
	
	stdio_write("keyboard repeater\n");
	while (1){
		uint8_t get_stat = stdio_get(&char_out);	// Get key status
		if (get_stat!=0){
			stdio_c(char_out);						// If there is any data print it
			
			
			
			
			

			set_led(((char_out>>1)&0x03),char_out&0x01);
			
			
			
			
			
			
			video_set_color(15,char_out);	//set some funny color next time
		}
	}
}

