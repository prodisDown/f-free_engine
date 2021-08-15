#include "screen.h"

#define DEFAULT_WINDOW_TITLE ("IndiGame")
#define DEFAULT_VIDEO_DRIVER (NULL)	// Default driver
#define DEFAULT_WINDOW_FLAGS (SDL_WINDOW_OPENGL |	\
		SDL_WINDOW_FULLSCREEN_DESKTOP |		\
		SDL_WINDOW_INPUT_GRABBED		)
#define DEFAULT_WINDOW_SIZE_W 640
#define DEFAULT_WINDOW_SIZE_H 320


struct Screen screen;	// global struct, check 'screen.h'


static int init(void)
{
	if (SDL_VideoInit(DEFAULT_VIDEO_DRIVER))
		return (-1);

	screen.window = SDL_CreateWindow(DEFAULT_WINDOW_TITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		DEFAULT_WINDOW_SIZE_W, DEFAULT_WINDOW_SIZE_H,
		DEFAULT_WINDOW_FLAGS);
	screen.glcontext = SDL_GL_CreateContext(screen.window);
	if (screen.window == NULL || screen.glcontext == 0)
		return (-1);

	return 0;
}


int screen_start(void)
{
	if (init())
		return (-1);

	return 0;
}

void screen_swap(void)
{
	SDL_GL_SwapWindow(screen.window);
}


