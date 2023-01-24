#include "game.h"

void Game::start(Player * player) {
	map.load();
	while (true) {
		if (key->getKeyState() >= 1) {
			map.move(player);
		}
	}
}