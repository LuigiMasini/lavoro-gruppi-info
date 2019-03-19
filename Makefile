# x86: main.cpp
# 	g++ -O2 -m32 -o example $< ../../api/lib/libfmodex.so
# 
# x64: main.cpp
# 	g++ -O2 -m64 -o example $< ../../api/lib/libfmodex64.so

x86_c: playstream.c
	g++ -O2 -m32 -o play $< ../../api/lib/libfmodex.so

x64_c: playstream.c
	g++ -O2 -m64 -o play $< ../../api/lib/libfmodex64.so

clean:
	rm -f example
