#MAKEFILE per progetto info per stampare figure

DIR=src/
FLAGS= -L $(DIR)lib/ -std=c99 -D _DEFAULT_SOURCE -Wall -Werror


ifeq ($(OS),Windows_NT)
	TARGET =WIN32
	FLAGS += -D WIN
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		FLAGS += -D LINUX
		UNAME_P := $(shell uname -m)
		ifeq ($(UNAME_P),x86_64)
			TARGET =LINUX64
		endif
		ifeq ($(UNAME_P),i686)
			TARGET =LINUX32
		endif
		ifeq ($(UNAME_P),i386)
			TARGET =LINUX32
		endif
		ifneq ($(filter %86,$(UNAME_P)),)
			TARGET =LINUXIA32
		endif
		ifneq ($(filter arm%,$(UNAME_P)),)
			TARGET =LINUXARM
		endif
	endif
	ifeq ($(UNAME_S),Darwin)
		TARGET =OSX
		FLAGS += -D OSX
	endif
endif


all: $(TARGET)

WIN32:
	$(CC) $(FLAGS) $(DIR)menu.c $(DIR)figure.c $(DIR)omino.c -o menu.exe -lwinmm

LINUX32:
	$(CC) $(FLAGS) -O2 -m32 -o linux_play  $(DIR)playstream.c $(DIR)lib/libfmodex.so
	$(CC) $(FLAGS) $(DIR)menu.c $(DIR)figure.c $(DIR)omino.c -o menu

LINUX64: 
	$(CC) $(FLAGS) -O2 -m64 -o linux_play $(DIR)playstream.c $(DIR)lib/libfmodex64.so
	$(CC) $(FLAGS) $(DIR)menu.c $(DIR)figure.c $(DIR)omino.c -o menu

OSX:
	$(CC) $(FLAGS) $(DIR)menu.c $(DIR)figure.c $(DIR)omino.c -o menu

clean:
	rm -f linux_play omino omino.exe menu menu.exe
clear: clean
