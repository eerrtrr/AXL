AXL_test: main.o AXL.o Logger.o 
	gcc -o run main.o AXL.o Logger.o -L/usr/X11/lib -lX11
	make rm

main.o : main.c AXL.h Logger.h
	gcc -c -Wall main.c

AXL.o : AXL.c AXL.h
	gcc -c -Wall AXL.c
	
Logger.o : Logger.c	Logger.h
	gcc -c -Wall Logger.c
rm :
	rm *.o
