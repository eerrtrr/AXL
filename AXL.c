#include "AXL.h"




//......................DISPLAY STUFF......................//


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
	XSetForeground(win->display, win->gc, BlackPixel(win->display, win->screen));
	XSelectInput(win->display, win->window, StructureNotifyMask);

	return win;
}

window* createWindow(unsigned int x, unsigned int y, unsigned int border_width, unsigned int width, unsigned int height){
	window* win = initialiseWindow(x, y, border_width, width, height);
	XMapWindow(win->display, win->window);
	for(;;){
	    XEvent e;
	    XNextEvent(win->display, &e);
	    if (e.type == MapNotify)
		  break;
      }

	return win;
}



//......................STRUCT CREATION......................//

points* createPointList(unsigned int nbr, short coords[][2]){
	points* pts = malloc(sizeof(points));
	pts->nbr = nbr;
	XPoint* xpts = malloc(nbr*sizeof(XPoint));
	
	for(int i=0; i<nbr; i++){
		xpts[i].x = coords[i][0];
		xpts[i].y = coords[i][1];	
	}

	pts->points = xpts;

	return pts;
}



//......................DRAWING FUNCTIONS......................//

void drawPoint(window* win, unsigned int x, unsigned int y){
	XDrawPoint(win->display, win->window, win->gc, x, y);
}

void drawPoints(window* win, points* pts){
	XDrawPoints(win->display, win->window, win->gc, pts->points, pts->nbr, CoordModeOrigin);
}


void drawLine(window* win, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2){
	XDrawLine(win->display, win->window, win->gc, x1, y1, x2, y2);
}
void drawLines(window* win, points* pts){
	XDrawLines(win->display, win->window, win->gc, pts->points, pts->nbr, CoordModeOrigin);
}



void drawSqare(window* win, unsigned int x, unsigned int y, unsigned int length, bool fill){
	if(fill)
		XFillRectangle(win->display, win->window, win->gc, x, y, length, length);
	else
		XDrawRectangle(win->display, win->window, win->gc, x, y, length, length);
}

void drawRectangle(window* win, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool fill){
	if(fill)
		XFillRectangle(win->display, win->window, win->gc, x, y, width, height);
	else
		XDrawRectangle(win->display, win->window, win->gc, x, y, width, height);
}

void drawCircle(window* win, unsigned int x, unsigned int y, unsigned int radius, bool fill){
	if(fill)
		XFillArc(win->display, win->window, win->gc, x, y, radius, radius, 0, 23040);
	else
		XDrawArc(win->display, win->window, win->gc, x, y, radius, radius, 0, 23040);
}

void drawElipse(window* win, unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int angle1, unsigned int angle2, bool fill){
	if(fill)
		XFillArc(win->display, win->window, win->gc, x, y, width, height, angle1, angle2);
	else
		XDrawArc(win->display, win->window, win->gc, x, y, width, height, angle1, angle2);
}

void cleanWindow(window* win){
	XClearWindow(win->display, win->window);
}