PowWifi.o: PowWiFi.c
	gcc -Wall -Werror PowWiFi.c -o PowWiFi.o

run: PowWiFi.o
	./PowWiFi.o &



clean: 
	rm -rf PowWiFi.o
