# include <stdio.h>
# include <stdlib.h>
#include "AXL.h"
#include "unistd.h"



int main(int argc, char** argv){
	
	window* window = createWindow(50, 50, 1, 500, 500);
	setColor(window, 105,150,105);
	sleep(1);
	drawRectangle(window, 20, 20, 125, 70, true);
	XFlush(window->display);

	while(1){
		XEvent e;
	    XNextEvent(window->display, &e); 

		switch (e.type){
			case Expose:
				
				break;
			case ButtonPress:
				
				break;
			case KeyPress:
				
				break;
			case ConfigureNotify:
				window->x = e.xconfigure.x;		window->y = e.xconfigure.y;		window->width = e.xconfigure.width;		window->height = e.xconfigure.height;
			break;
		}
	}

	return 0;
}		