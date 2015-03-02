all: libstatic
	mkdir -p out
	g++ src/main/main.cpp lib/libstatic.o -o out/main.exe

clear:
	rm -rf out lib

libstatic:
	mkdir -p lib
	g++ -c src/lib/mytimefunctions.cpp -o lib/libstatic.o

libshared:
	mkdir -p lib
	g++ -fPIC -c src/lib/mytimefunctions.cpp -o lib/lib.o
	g++ -shared lib/lib.o -o lib/libshared.so
	rm lib/lib.o
