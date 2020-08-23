# include <stdio.h>
# include <stdlib.h>
#include "AXL.h"
#include "unistd.h"



int main(int argc, char** argv){
	
	window* window = createWindow(50, 50, 1, 500, 500);

	short pts[][2] = {{5,2}, {80,60}, {412,21}, {125,129}};
	drawCircle(window, 120, 150, 400, 1);

	XFlush(window->display);

	sleep(2);
	
	cleanWindow(window);

	XFlush(window->display);
	sleep(2);

	return 0;
}