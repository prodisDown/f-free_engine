#ifndef screen_h
#define screen_h

#include <SDL2/SDL.h>


extern struct Screen
{
	SDL_Window *window;
	SDL_DisplayMode mode;
	SDL_GLContext glcontext;
} screen;


enum Screen_Dimension
{
	SCREEN_DIM_FULLSCREEN,
	SCREEN_DIM_640x320
};


extern int screen_start(void);
extern void screen_swap(void);

#endif /* screen_h */
