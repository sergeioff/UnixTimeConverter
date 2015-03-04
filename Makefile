all:
	mkdir -p lib bin
	g++ -shared -fPIC src/lib/mytimefunctions.cpp -o lib/libmytimefunctions.so
	g++ src/main/main.cpp -o bin/mytestprogram -L lib -lmytimefunctions

clear:
	rm -rf lib bin

install: 
	cp lib/libmytimefunctions.so /usr/lib/
	cp bin/mytestprogram /usr/bin
	@echo program successfully installed! You can run it by typing "mytestprogram"

uninstall:
	rm rf -f /usr/lib/libmytimefunctions.so /usr/bin/mytestprogram
	@echo program successfully uninstalled!
