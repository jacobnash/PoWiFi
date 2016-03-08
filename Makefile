PowWifi.o: PowWifi.c
	gcc -Wall -Werror std=c99 PowWifi.c -o PowWifi.o

run: PowWifi.o
	./PowWifi.o &



clean: 
	rm -rf PowWifi.o
