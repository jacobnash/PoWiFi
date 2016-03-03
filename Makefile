PowWifi.o:
	gcc -Wall -Werror PowWifi.c -o PowWifi.o

run: PowWifi.o
	./PowWifi.o

