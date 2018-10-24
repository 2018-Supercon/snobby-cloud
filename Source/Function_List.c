
There are four categories of functions:
-hard_func
-initialize
-screen_manip
-core_func

a "??" behind commnets means I have looked and don't know what the function does
a comment enclosed in "??" means I think but I am not 100% sure
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Category				Funcion Name																			Function Description
----------------------- --------------------------------------------------------------------------------------- ----------------------------------------------------------------------------------------------------------------
// From badge.h	
initialize	 			terminal_init(void);																	// Initialize terminal (Not Defined - use term_init())
core_func				term_k_stat(void);																		// ?? get the status of the terminal key ??
core_func				term_k_char(int8_t * out);																// ?? Set the character for the terminal prompt ??
hard_func				rx_sta(void);																			// ?? Checks if data on serial ??
hard_func				rx_read(void);																			// Read data on serial receive
hard_func				tx_write(uint8_t data);																	// Write data to serial transmit
core_func				stdio_local_buffer_state(void);															// 
core_func				stdio_local_buffer_get(void);															// 
core_func				stdio_local_buffer_put(int8_t data);													// 
core_func				stdio_local_buffer_puts(int8_t * data);													// 
						get_user_value(void);																	// ??
screen_manip			enable_display_scanning(uint8_t onoff);													// Turn display scanning on or off
core_func				millis(void);																			// Returns number of milliseconds past power on
screen_manip			display_refresh_force(void);															// Force refresh the screen
screen_manip			clr_buffer(void);																		// Clears display buffer
----------------------- --------------------------------------------------------------------------------------- ----------------------------------------------------------------------------------------------------------------
// From hw.h
core_func				wait_1ms(void);																			// Waits 1 millisecond
core_func				wait_ms(uint32_t count);																// Waits count # of millisecond
						keyb_tasks(void);																		// ??
initialize	 			hw_init(void);																			// Initialize hardware
hard_func				hw_sleep(void);																			// Set mode for low Power Mode
hard_func				(*start_after_wake)(void);																// ?? What to do after waking up ??
hard_func				wake_return(void);																		// What to do upon wake from low Power Mode
hard_func				set_led(uint8_t led_n, uint8_t led_v);													// Sets LED to led_n color, and led_v value
						get_rnd(void);																			// ??
						exp_set(uint8_t pos, uint8_t val);														// 
						exp_ddr(uint8_t pos, uint8_t val);														// 
						exp_get(uint8_t pos);																	// 
						get_led_word(void);																		// 
						set_led_word(uint8_t val);																// 
initialize	 			init_io(uint8_t mode);																	// Initialize the I/O pins on the chip
screen_manip			stdio_write(int8_t * data);																// Write null-terminated string to standard output
						stdio_c(uint8_t data);																	// 
						stdio_in(uint8_t block);																// 
						stdio_get_state(void);																	// 
						stdio_get(int8_t * dat);																// 
hard_func				serial_flush(void);																		// Clear data on serial
hard_func				rx_sta(void);																			// ?? Checks if data on serial ??
hard_func				rx_read(void);																			// Read data on serial receive
hard_func				tx_write(uint8_t data);																	// Write data to serial transmit
----------------------- --------------------------------------------------------------------------------------- ----------------------------------------------------------------------------------------------------------------
// From disp.h
hard_func				TFT_24_7789_Init(void);																	// 
hard_func				TFT_24_7789_Write_Data(uint16_t data1);													// 
hard_func				TFT_24_7789_Write_Data3(uint16_t data1,uint16_t data2, uint16_t data3);					// 
hard_func				TFT_24_7789_Write_Command(uint16_t command);											// 
hard_func				tft_set_write_area(uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen);				// 
hard_func				tft_print_char(uint8_t val, uint16_t x, uint16_t y, uint32_t col, uint32_t back);		// 
hard_func				tft_fill_area(uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen, uint32_t back);		// 
hard_func				tft_disp_buffer_refresh(uint8_t * buff, uint8_t * color_buff);							// 
hard_func				tft_disp_buffer_refresh_part(uint8_t * buff, uint8_t * color_buff);						// 
						disp_tasks(void);																		// 
						set_cursor_state(uint8_t state);														// 
----------------------- --------------------------------------------------------------------------------------- ----------------------------------------------------------------------------------------------------------------
// From vt100.h
core_func				escseq_process(int8_t c);																// Escape sequence processing
core_func				escseq_process_noncsi(int8_t c);														// Escape sequence processing for non-CSI codes
core_func				escseq_process_csi(int8_t c);															// Escape sequence processing for CSI codes
core_func				escseq_csi_start(void);																	// ?? Sets first non-ESC character in escape sequence ??
core_func				escseq_get_param(uint8_t defaultval);													// Gets the parameters of the escape sequence
core_func				receive_char(uint8_t c);																// Processes character data to be sent to screen
screen_manip			save_term_state(void);																	// Save terminal settings
screen_manip			restore_term_state(void);																// Restore terminal settings
screen_manip			reset_term(void); 																		// Reset terminal
core_func				buf_dequeue(void);																		// Removes data to the buffer queue 
core_func				buf_enqueue(uint8_t c);																	// Adds data to the buffer queue 
screen_manip			video_set_margins(int8_t top, int8_t bottom);											// Set the top and bottom margins. The cursor is moved to the first column of the top margin
screen_manip			video_reset_margins(void);																// Resets the top margin to the top line of the screen and the bottom margin to the bottom line of the screen
screen_manip			video_top_margin(void);																	// Returns the line number of the top margin
screen_manip			video_bottom_margin(void);																// Returns the line number of the bottom margin
screen_manip			video_set_reverse(uint8_t val);															// Sets whether or not the screen should be displayed in reverse video
screen_manip			video_clrscr(void);																		// Clears the screen, returns the cursor to (0,0), and resets the margins to the full size of the screen
screen_manip			video_clrline(void);																	// Clears the current line and returns the cursor to he start of the line
screen_manip			video_clreol(void);																		// Clears the rest of the line from the cursor position to the end of the line without moving the cursor
screen_manip			video_erase(uint8_t erasemode);															// erasemode = 0: erase from the cursor (inclusive) to the end of the screen
																												// erasemode = 1: erase from the start of the screen to the cursor (inclusive)
																												// erasemode = 2: erase the entire screen
																												// The cursor does not move
																												// This call corresponds to the ANSI "Erase in Display" escape sequence
screen_manip			video_eraseline(uint8_t erasemode);														// erasemode = 0: erase from the cursor (inclusive) to the end of the line
																												// erasemode = 1: erase from the start of the line to the cursor (inclusive)
																												// erasemode = 2: erase the entire line
																												// The cursor does not move
																												// This call corresponds to the ANSI "Erase in Line" escape sequence
screen_manip			video_setc(int8_t c);																	// Overwrites the character at the cursor position without moving it
screen_manip			video_putc(int8_t c);																	// Prints a character at the cursor position and advances the cursor. Carriage returns and newlines are interpreted
screen_manip			video_putc_raw(int8_t c);																// Prints a character at the cursor position and advances the cursor. Carriage returns and newlines are not interpreted
screen_manip			video_puts(int8_t *str);																// Prints a string at the cursor position and advances the cursor. The screen will be scrolled if necessary
screen_manip			video_putcxy(int8_t x, int8_t y, int8_t c);												// Prints a string from program memory at the cursor position and advances the cursor. The screen will be scrolled if necessary
screen_manip			video_putsxy(int8_t x, int8_t y, int8_t *str);											// Prints a string at the specified position. Escape characters are not interpreted. The cursor is not advanced and the screen is not scrolled
screen_manip			video_putline(int8_t y, int8_t *str);													// Prints a string from program memory at the specified position. Escape characters are not interpreted. The cursor is not advanced and the screen is not scrolled
screen_manip			video_gotoxy(int8_t x, int8_t y);														// Prints a string from program memory on the specified line. The previous contents of the line are erased. Escape characters are not interpreted. The cursor is not advanced and the screen is not scrolled
screen_manip			video_movex(int8_t dx);																	// Moves the cursor left/right by the specified number of columns
screen_manip			video_movey(int8_t dy);																	// Moves the cursor up/down the specified number of lines.  The cursor does not move beyond the top/bottom margins
screen_manip			video_movesol(void);																	// Moves the cursor to the start of the current line
screen_manip			video_setx(int8_t x);																	// Sets the horizontal position of the cursor
screen_manip			video_cfwd(void);																		// Advances the cursor one character to the right, advancing to a new line if necessary
screen_manip			video_lfwd(void);																		// Advances the cursor one line down and moves it to the start of the new line. The screen is scrolled if the bottom margin is exceeded
screen_manip			video_lf(void);																			// Advances the cursor one line down but does not return the cursor to the start of the new line. The screen is scrolled if the bottom margin is exceeded
screen_manip			video_cback(void);																		// Moves the cursor one character back, moving to the end of the previous line if necessary
screen_manip			video_lback(void);																		// Moves the cursor to the end of the previous line, or to the first column of the top margin if the top margin is exceeded
screen_manip			video_scrollup(void);																	// Scrolls the region between the top and bottom margins up one line. A blank line is added at the bottom. The cursor is not moved
screen_manip			video_scrolldown(void);																	// Scrolls the region between the top and bottom margins down one line. A blank lines is added at the top. The cursor is not moved
screen_manip			video_getx(void);																		// Returns the x coordinate of the cursor
screen_manip			video_gety(void);																		// Returns the y coordinate of the cursor
screen_manip			video_charat(int8_t x, int8_t y);														// Returns the character at the specified position
screen_manip			video_show_cursor(void);																// Shows the cursor. Off by default
screen_manip			video_hide_cursor(void);																// Hides the cursor
screen_manip			video_cursor_visible();																	// Returns 1 if the cursor is visible, 0 if it is hidden
screen_manip			video_invert_range(int8_t x, int8_t y, uint8_t rangelen);								// Set inverse video for the character range specified
Dead Function			CURSOR_INVERT(void);																	// Literally empty function 
*use parent func*		_video_scrollup(void);																	// Scrolls the screen up by one line
*use parent func*		_video_scrolldown(void);																// Scrolls the screen down by one line
*use parent func*		_video_lfwd(void);																		// Moves cursor one position to the right
*use parent func*		_video_cfwd(void);																		// Moves cursor down one line
*use parent func*		_video_lback(void);																		// Moves cursor one position to the left
screen_manip			_video_scrollup_lin(uint8_t lin);														// Scrolls the screen up by lin number of lines
screen_manip			_video_scrolldown_lin(uint8_t line);													// Scrolls the screen down by line number of lines
initialize	 			term_init(void);																		// Initialize terminal
screen_manip			video_set_color(uint8_t fg, uint8_t bg);												// Set screen foreground(fg) and background (bg)
----------------------- --------------------------------------------------------------------------------------- ----------------------------------------------------------------------------------------------------------------
