AXL_test: main.o AXL.o
	gcc -o exe main.o AXL.o -L/usr/X11/lib -lX11
	make rm

main.o : main.c AXL.h
	gcc -c -Wall main.c

AXL.o : AXL.c AXL.h
	gcc -c -Wall AXL.c
	
rm :
	rm *.o
