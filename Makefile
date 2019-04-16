#MAKEFILE per progetto info per stampare figure

DIR=src/


ifeq ($(OS),Windows_NT)
	CCFLAGS+=WIN32
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		UNAME_P := $(shell uname -m)
		ifeq ($(UNAME_P),x86_64)
			CCFLAGS +=LINUX64
		endif
		ifeq ($(UNAME_P),i686)
			CCFLAGS +=LINUX32
		endif
		ifeq ($(UNAME_P),i386)
			CCFLAGS +=LINUX32
		endif
		ifneq ($(filter %86,$(UNAME_P)),)
			CCFLAGS +=LINUXIA32
		endif
		ifneq ($(filter arm%,$(UNAME_P)),)
			CCFLAGS +=LINUXARM
		endif
	endif
	ifeq ($(UNAME_S),Darwin)
		CCFLAGS +=OSX
	endif
endif

all: $(CCFLAGS)

WIN32:
	gcc $(DIR)omino.c -o omino.exe -lwinmm
	gcc $(DIR)menu.c -o menu.exe

LINUX32: $(DIR)playstream.c
	gcc -O2 -m32 -o linux_play $< $(DIR)lib/libfmodex.so
	gcc $(DIR)omino.c -o omino
	gcc $(DIR)menu.c -o menu

LINUX64: $(DIR)playstream.c
	gcc -O2 -m64 -o linux_play $< $(DIR)lib/libfmodex64.so
	gcc $(DIR)omino.c -o omino
	gcc $(DIR)menu.c -o menu

clean:
	rm -f linux_play omino omino.exe menu menu.exe
