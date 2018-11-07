uint32_t  hash(int8_t *command){
	uint32_t  hash = 0;
	uint8_t infinite_loop_breaker = 0;
	uint8_t c;
	while (c = *command++){
		hash = (hash*33)^c;
		if (infinite_loop_breaker++ > 100){
			return 0;
		}
	}
	return hash;
}



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