#include "AXL.h"


window* initialiseWindow(unsigned int x, unsigned int y, unsigned int border_width, unsigned int width, unsigned int height){
	
	window* win = malloc(sizeof(window));
	win->display = XOpenDisplay(NULL);

 	win->screen = DefaultScreen(win->display);
 	win->x = x;		win->y = y;		win->border_width = border_width;
 	win->width = width;		win->height = height;
 	win->border = BlackPixel(win->display, win->screen);
 	win->background = WhitePixel(win->display, win->screen);

 	win->window = XCreateSimpleWindow(win->display, DefaultRootWindow(win->display), x, y, width, height, border_width, win->border, win->background);
	win->gc = XCreateGC(win->display, win->window, 0, NULL);
	XSetForeground(win->display, win->gc, win->border);

	return win;
}


void displayWindow(window* win){
	XMapWindow(win->display, win->window);
}


window* createWindow(unsigned int x, unsigned int y, unsigned int border_width, unsigned int width, unsigned int height){
	window* win = initialiseWindow(x, y, border_width, width, height);
	XMapWindow(win->display, win->window);

	return win;
}