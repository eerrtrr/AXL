# include <stdio.h>
# include <stdlib.h>
#include "AXL.h"
#include "unistd.h"



int main(int argc, char** argv){
	
	window* window = createWindow(50, 50, 1, 500, 500);

	for(;;) {
	    XEvent e;
	    XNextEvent(window->display, &e);
	    if (e.type == MapNotify)
		  break;
    }
	

	return 0;
}