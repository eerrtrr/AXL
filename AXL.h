#ifndef AXL_H
#define AXL_H


#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
# include <stdio.h>
# include <stdlib.h>

struct WINDOW{
	Display* display;
	Window window;
	int screen; 
	GC gc;
	unsigned int x, y, border_width, width, height;
	unsigned long border;
    unsigned long background;
};
typedef struct WINDOW window;


window* initialiseWindow(unsigned int x, unsigned int y, unsigned int border_width, unsigned int width, unsigned int height);
void displayWindow(window* win);
window* createWindow(unsigned int x, unsigned int y, unsigned int border_width, unsigned int width, unsigned int height);


//Drawing functions


#endif