#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#include "game.h"
#include "graphics.h"
#include "screen.h"
#include "input.h"

static int game_loop(void);

int game_main(void)
{
	game_loop();

	return 0;
}

int game_loop(void)
{
	while (true)
	{
		usleep(16000);
		opengl_draw();
		screen_swap();
	};

	return 0;
}
