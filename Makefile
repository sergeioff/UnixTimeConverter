all:
	mkdir -p lib
	g++ -shared -fPIC src/lib/mytimefunctions.cpp -o lib/libmytimefunctions.so
	@echo mytimefunctions library created!

clear:
	rm -rf lib

install: 
	cp lib/libmytimefunctions.so /usr/lib/
	g++ src/main/main.cpp -o /usr/bin/mytestprogram -lmytimefunctions
	@echo program successfully installed! You can run it by typing "mytestprogram"

uninstall:
	rm rf -f /usr/lib/libmytimefunctions.so /usr/bin/mytestprogram
	@echo program successfully uninstalled!
