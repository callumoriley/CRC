SHELL=cmd
CC = gcc
SRC = main.c CRC.c binfunctions.c

a.exe: $(SRC)
	$(CC) $(SRC)
	@echo Compilation successful!