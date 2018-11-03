@echo off
REM This compiles the c code for Snobby Cloud Linux
REM programs required for this to work:
REM 	microchip's xc32++ compiler suite (used to compile code - duh)
REM 	pic32prog (used for uploading to the badge with an arduino) see: https://hackaday.io/project/27250-mcu-how-tos-reviews-rants/log/148016-programming-pic32-with-arduino
REM ---------------------------------------------------------------------------------

REM Booleans 1=True; 0=False
set PAUSE_AFTER_EACH=0
set PAUSE_PRE_EXIT=0
set COMPILE=1
set CONVERT=1
set UPLOAD=1

REM Stuff for compilation
set COMPILER=xc32-gcc.exe
set HEX_CONVERTER=xc32-bin2hex.exe
set INTERM_TYPE=.elf
set OUTPUT_TYPE=.hex
set PROCESSOR=32MX370F512H
set HEAP_SIZE=0xF000
set FILES=main.c badge.c hw.c disp.c vt100.c my_func.c
set SRC_PATH=Source
set BIN_PATH=Compiled

REM Stuff for writing to badge
set BADGE_WRITER=pic32prog.exe
set COMPORT=COM3

REM Name of the executable
set OUTPUT_NAME=snobby-cloud-v0.1

cls
IF %COMPILE% EQU 1 (
	echo --------------------------------Compiling Source--------------------------------
	cd %SRC_PATH%
	%COMPILER% -Wl,--defsym=_min_heap_size=%HEAP_SIZE% -mprocessor=%PROCESSOR% %FILES% -o ..\%BIN_PATH%\%OUTPUT_NAME%%INTERM_TYPE%
	cd ..\
	echo.
	echo --------------------------------------Done--------------------------------------
	IF %PAUSE_AFTER_EACH% EQU 1 (
		pause
	) ELSE ( 
		echo.
	)
)
pause
IF %CONVERT% EQU 1 (
	echo -----------------------------Converting to Hex File-----------------------------
	cd %BIN_PATH%
	%HEX_CONVERTER% %OUTPUT_NAME%%INTERM_TYPE%
	cd ..\
	echo.
	echo --------------------------------------Done--------------------------------------
	IF %PAUSE_AFTER_EACH% EQU 1 (
		pause
	) ELSE ( 
		echo.
	)
)

IF %UPLOAD% EQU 1 (
	echo --------------------------------Writing to Badge--------------------------------
	cd %BIN_PATH%
	%BADGE_WRITER% -d ascii:%COMPORT% %OUTPUT_NAME%%OUTPUT_TYPE%
	cd ..\
	echo.
	echo --------------------------------------Done--------------------------------------
	IF %PAUSE_AFTER_EACH% EQU 1 (
		pause
	) ELSE ( 
		echo.
	)
)

echo --------------------------------Compile Finished--------------------------------
IF %PAUSE_PRE_EXIT% EQU 1 (
	pause
) 