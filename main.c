# include <stdio.h>
# include <stdlib.h>
#include "AXL.h"
#include "unistd.h"
#include "Logger.h"

int x = 0;
int y = 0;


int main(int argc, char** argv){
	
	window* window = createWindow(50, 50, 1, 500, 500, "C'EST UNE FENETRE");
	unsigned long color = addColor(window, 255,0,0);
	setColor(window, color);
/*
	for(int i=0; i<600; i++){
		cleanWindow(window);
		drawRectangle(window, x, y, 125, 70, true);
		XFlush(window->display);
		x++;	y++;
		usleep(100000);
	}
*/

	while(window->exist){
		XEvent e;
	    XNextEvent(window->display, &e); 

		switch (e.type){
			case Expose:
				
				break;
				
			case ButtonPress:
				
				break;
				
			case KeyPress:
				
				break;
				
			case ClientMessage:
				if((Atom)e.xclient.data.l[0] == window->close)
				{
					window->exist = false;
				}
				break;
				
			case ConfigureNotify:
				window->x = e.xconfigure.x;		window->y = e.xconfigure.y;		window->width = e.xconfigure.width;		window->height = e.xconfigure.height;
				log_trace("%d", window->x);
			break;
		}
	}
	destroyWindow(window);
	return 0;
}		
