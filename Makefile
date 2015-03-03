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
	g++ -shared -fPIC src/lib/mytimefunctions.cpp -o lib/libmytimefunctions.so

install: 
	g++ -shared -fPIC src/lib/mytimefunctions.cpp -o /usr/lib/libmytimefunctions.so
	g++ src/main/main.cpp -o /usr/bin/mytestprogram -lmytimefunctions

uninstall:
	rm rf -f /usr/lib/libmytimefunctions.so /usr/bin/mytestprogram
