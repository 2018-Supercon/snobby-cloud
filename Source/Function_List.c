
Category			Funcion Name																			Function Description
					
// From badge.h
					terminal_init(void);																	// Initialize terminal
					term_k_stat (void);																		// 
					term_k_char (int8_t * out);																// 
					rx_sta (void);																			// 
					rx_read (void);																			// Read data on serial receive
					tx_write (uint8_t data);																// Write data to serial transmit
					stdio_local_buffer_state (void);														// 
					stdio_local_buffer_get (void);															// 
					stdio_local_buffer_put (int8_t data);													// 
					stdio_local_buffer_puts (int8_t * data);												// 
					get_user_value (void);																	// 
					enable_display_scanning(uint8_t onoff);													// 
					millis(void);																			// 
					display_refresh_force (void);															// 
					clr_buffer (void);																		// 

// From hw.h
					wait_1ms (void);																		// Pretty obvious right?
					wait_ms (uint32_t count);																// Also fairly obvious...
					keyb_tasks (void);																		// 
					hw_init (void);																			// Initialize hardware
					hw_sleep (void);																		// Set mode for low Power Mode
					(*start_after_wake)(void);																// ??
					wake_return(void);																		// What to do upon wake from low Power Mode
					set_led (uint8_t led_n, uint8_t led_v);													// 
					get_rnd (void);																			// 
					exp_set(uint8_t pos, uint8_t val);														// 
					exp_ddr(uint8_t pos, uint8_t val);														// 
					exp_get (uint8_t pos);																	// 
					get_led_word(void);																		// 
					set_led_word (uint8_t val);																// 
					init_io(uint8_t mode);																	// 
					stdio_write (int8_t * data);															// Parent function to print data to screen or over serial
					stdio_c (uint8_t data);																	// 
					stdio_in (uint8_t block);																// 
					stdio_get_state (void);																	// 
					stdio_get (int8_t * dat);																// 
					serial_flush (void);																	// Clear data on serial
					rx_sta (void);																			// 
					rx_read (void);																			// Read data on serial receive
					tx_write (uint8_t data);																// Write data to serial transmit

// From disp.h
					TFT_24_7789_Init(void);																	// 
					TFT_24_7789_Write_Data(uint16_t data1);													// 
					TFT_24_7789_Write_Data3(uint16_t data1,uint16_t data2, uint16_t data3);					// 
					TFT_24_7789_Write_Command(uint16_t command);											// 
					tft_set_write_area (uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen);				// 
					tft_print_char (uint8_t val, uint16_t x, uint16_t y, uint32_t col, uint32_t back);		// 
					tft_fill_area (uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen, uint32_t back);	// 
					tft_disp_buffer_refresh(uint8_t * buff, uint8_t * color_buff);							// 
					tft_disp_buffer_refresh_part(uint8_t * buff, uint8_t * color_buff);						// 
					disp_tasks (void);																		// 
					set_cursor_state (uint8_t state);														// 

// From vt100.h
					escseq_process(int8_t c);																// 
					escseq_process_noncsi(int8_t c);														// 
					escseq_process_csi(int8_t c);															// 
					escseq_csi_start(void);																	// 
					escseq_get_param(uint8_t defaultval);													// 
					receive_char(uint8_t c);																// 
					save_term_state(void);																	// 
					restore_term_state(void);																// 
					reset_term(void); 																		// 
					buf_dequeue(void);																		// 
					buf_enqueue(uint8_t c);																	// 
					video_set_margins(int8_t top, int8_t bottom);											// Set the top and bottom margins. The cursor is moved to the first column of the top margin
					video_reset_margins(void);																// Resets the top margin to the top line of the screen and the bottom margin to the bottom line of the screen
					video_top_margin(void);																	// Returns the line number of the top margin
					video_bottom_margin(void);																// Returns the line number of the bottom margin
					video_set_reverse(uint8_t val);															// Sets whether or not the screen should be displayed in reverse video
					video_clrscr(void);																		// Clears the screen, returns the cursor to (0,0), and resets the margins to the full size of the screen
					video_clrline(void);																	// Clears the current line and returns the cursor to he start of the line
					video_clreol(void);																		// Clears the rest of the line from the cursor position to the end of the line without moving the cursor
					video_erase(uint8_t erasemode);															// erasemode = 0: erase from the cursor (inclusive) to the end of the screen
																											// erasemode = 1: erase from the start of the screen to the cursor (inclusive)
																											// erasemode = 2: erase the entire screen
																											// The cursor does not move
																											// This call corresponds to the ANSI "Erase in Display" escape sequence
					video_eraseline(uint8_t erasemode);														// erasemode = 0: erase from the cursor (inclusive) to the end of the line
																											// erasemode = 1: erase from the start of the line to the cursor (inclusive)
																											// erasemode = 2: erase the entire line
																											// The cursor does not move
																											// This call corresponds to the ANSI "Erase in Line" escape sequence
					video_setc(int8_t c);																	// Overwrites the character at the cursor position without moving it
					video_putc(int8_t c);																	// Prints a character at the cursor position and advances the cursor. Carriage returns and newlines are interpreted
					video_putc_raw(int8_t c);																// Prints a character at the cursor position and advances the cursor. Carriage returns and newlines are not interpreted
					video_puts(int8_t *str);																// Prints a string at the cursor position and advances the cursor. The screen will be scrolled if necessary
					video_putcxy(int8_t x, int8_t y, int8_t c);												// Prints a string from program memory at the cursor position and advances the cursor. The screen will be scrolled if necessary
					video_putsxy(int8_t x, int8_t y, int8_t *str);											// Prints a string at the specified position. Escape characters are not interpreted. The cursor is not advanced and the screen is not scrolled
					video_putline(int8_t y, int8_t *str);													// Prints a string from program memory at the specified position. Escape characters are not interpreted. The cursor is not advanced and the screen is not scrolled
					video_gotoxy(int8_t x, int8_t y);														// Prints a string from program memory on the specified line. The previous contents of the line are erased. Escape characters are not interpreted. The cursor is not advanced and the screen is not scrolled
					video_movex(int8_t dx);																	// Moves the cursor left/right by the specified number of columns
					video_movey(int8_t dy);																	// Moves the cursor up/down the specified number of lines.  The cursor does not move beyond the top/bottom margins
					video_movesol(void);																	// Moves the cursor to the start of the current line
					video_setx(int8_t x);																	// Sets the horizontal position of the cursor
					video_cfwd(void);																		// Advances the cursor one character to the right, advancing to a new line if necessary
					video_lfwd(void);																		// Advances the cursor one line down and moves it to the start of the new line. The screen is scrolled if the bottom margin is exceeded
					video_lf(void);																			// Advances the cursor one line down but does not return the cursor to the start of the new line. The screen is scrolled if the bottom margin is exceeded
					video_cback(void);																		// Moves the cursor one character back, moving to the end of the previous line if necessary
					video_lback(void);																		// Moves the cursor to the end of the previous line, or to the first column of the top margin if the top margin is exceeded
					video_scrollup(void);																	// Scrolls the region between the top and bottom margins up one line. A blank line is added at the bottom. The cursor is not moved
					video_scrolldown(void);																	// Scrolls the region between the top and bottom margins down one line. A blank lines is added at the top. The cursor is not moved
					video_getx(void);																		// Returns the x coordinate of the cursor
					video_gety(void);																		// Returns the y coordinate of the cursor
					video_charat(int8_t x, int8_t y);														// Returns the character at the specified position
					video_show_cursor(void);																// Shows the cursor. Off by default
					video_hide_cursor(void);																// Hides the cursor
					video_cursor_visible();																	// Returns 1 if the cursor is visible, 0 if it is hidden
					video_invert_range(int8_t x, int8_t y, uint8_t rangelen);								// Set inverse video for the character range specified
					CURSOR_INVERT(void);																	// 
					_video_scrollup(void);																	// 
					_video_scrolldown(void);																// 
					_video_lfwd(void);																		// 
					_video_cfwd(void);																		// 
					_video_lback(void);																		// 
					_video_scrollup_lin(uint8_t lin);														// 
					_video_scrolldown_lin(uint8_t line);													// 
					term_init (void);																		// 
					video_set_color(uint8_t fg, uint8_t bg);												// 