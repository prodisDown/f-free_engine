#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#include "screen.h"
#include "graphics.h"
#include "input.h"
#include "game.h"


int main(int argc, char *argv[])
{
	if (screen_start())
		return (-1);
	if (opengl_init())
		return (-1);

	game_main();

	return 0;
}
