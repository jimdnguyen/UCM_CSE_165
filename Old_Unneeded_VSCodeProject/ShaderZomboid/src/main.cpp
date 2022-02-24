#include "Interface.h"
#include "Game.h"

int main(int argc, char **argv)
{
	Interface *interface = new Interface();
	Game *game = new Game();

	interface->setup();
	game->setup();

	interface->run(game);

	delete game;
	delete interface;

	return 0;
}