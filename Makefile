all:
	mkdir -p lib
	g++ -shared -fPIC src/lib/mytimefunctions.cpp -o lib/libmytimefunctions.so

clear:
	rm -rf lib

install: 
	cp lib/libmytimefunctions.so /usr/lib/
	g++ src/main/main.cpp -o /usr/bin/mytestprogram -lmytimefunctions

uninstall:
	rm rf -f /usr/lib/libmytimefunctions.so /usr/bin/mytestprogram
