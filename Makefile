# x86: main.cpp
# 	g++ -O2 -m32 -o example $< ../../api/lib/libfmodex.so
# 
# x64: main.cpp
# 	g++ -O2 -m64 -o example $< ../../api/lib/libfmodex64.so

win:
	gcc omino.c -o omino.exe -lwinmm
	gcc menu.c -o menu.exe

lin_x86: playstream.c
	gcc -O2 -m32 -o linux_play $< lib/libfmodex.so
	gcc omino.c -o omino
	gcc menu.c -o menu

lin_x64: playstream.c
	gcc -O2 -m64 -o linux_play $< lib/libfmodex64.so
	gcc omino.c -o omino
	gcc menu.c -o menu

clean:
	rm -f linux_play omino omino.exe menu menu.exe
