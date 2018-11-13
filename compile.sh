#!/bin/bash
# This compiles the c code for Snobby Cloud Linux
# programs required for this to work:
#	microchip's xc32++ compiler suite (used to compile code - duh)
#	pic32prog (used for uploading to the badge with an arduino) see: https://hackaday.io/project/27250-mcu-how-tos-reviews-rants/log/148016-programming-pic32-with-arduino
# ---------------------------------------------------------------------------------

# Booleans 1=True; 0=False
PAUSE_AFTER_EACH=0
PAUSE_PRE_EXIT=0
COMPILE=0
CONVERT=0
UPLOAD=1

# Stuff for compilation
COMPILER=xc32-gcc
HEX_CONVERTER=xc32-bin2hex
INTERM_TYPE=.elf
OUTPUT_TYPE=.hex
PROCESSOR=32MX370F512H
HEAP_SIZE=0xF000
FILES=main.c badge.c hw.c disp.c vt100.c my_func.c
SRC_PATH=Source
BIN_PATH=Compiled

# Stuff for writing to badge
BADGE_WRITER=pic32prog
COMPORT=/dev/ttyUSB0

# Name of the executable
OUTPUT_NAME=snobby-cloud-v0.1

clear
if [ $COMPILE == 1 ]; then
	echo --------------------------------Compiling Source--------------------------------
	cd $SRC_PATH
	$COMPILER -Wl,--defsym=_min_heap_size=$HEAP_SIZE -mprocessor=$PROCESSOR $FILES -o ../$BIN_PATH/$OUTPUT_NAME$INTERM_TYPE
	cd ../
	echo ''
	echo --------------------------------------Done--------------------------------------
	if [ $PAUSE_AFTER_EACH == 1 ]; then
		read -n1 -r -p "Press any key to continue..." && echo ''
	else
		echo ''
	fi
fi

if [ $CONVERT == 1 ]; then
	echo -----------------------------Converting to Hex File-----------------------------
	cd $BIN_PATH
	$HEX_CONVERTER $OUTPUT_NAME$INTERM_TYPE
	# for /F "tokens=4" %%a in ('dir /-c %OUTPUT_NAME%%OUTPUT_TYPE%') do (
		# echo %%a
	#  )
	echo ''
	cd ../
	echo --------------------------------------Done--------------------------------------
	if [ $PAUSE_AFTER_EACH == 1 ]; then
		read -n1 -r -p "Press any key to continue..." && echo ''
	else
		echo ''
	fi
fi

if [ $UPLOAD == 1 ]; then
	echo --------------------------------Writing to Badge--------------------------------
	cd $BIN_PATH
	$BADGE_WRITER -d ascii:$COMPORT $OUTPUT_NAME$OUTPUT_TYPE
	cd ../
	echo ''
	echo --------------------------------------Done--------------------------------------
	if [ $PAUSE_AFTER_EACH == 1 ]; then
		read -n1 -r -p "Press any key to continue..." && echo ''
	else
		echo ''
	fi
fi

echo --------------------------------Compile Finished--------------------------------
if [ $PAUSE_PRE_EXIT == 1 ]; then
	read -n1 -r -p "Press any key to continue..." && echo ''
fi
