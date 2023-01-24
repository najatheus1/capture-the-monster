#include "map.h"
#include "monster.h"
#include "item.h"

Monster* monster = new Monster("demon", 10);
Item* item = new Item(1);

Map::Map() {
}

Map::~Map() {
}

void Map::load() {
	memset(map, 0, sizeof(map));
	for (std::size_t x = 0; x <= getSizeMap() - 1; ++x) {
		for (std::size_t y = 0; y <= getSizeMap() - 1; ++y) {
			this->map[x][y] = ' ';
		}
	}

	placeMonster();
}

void Map::move(Player * player) {
	clear();
	switch (key->getKeyState()) {
	case 0x1:
		player->getPosition()->setPosX(player->getPosition()->getPosX() - 1);
		if (player->getPosition()->getPosX() == -1) {
			player->getPosition()->setPosX(getSizeMap() - 1);
		}
		break;
	case 0x2:
		player->getPosition()->setPosX(player->getPosition()->getPosX() + 1);
		if (player->getPosition()->getPosX() == getSizeMap()) {
			player->getPosition()->setPosX(0);
		}
		break;
	case 0x4:
		player->getPosition()->setPosY(player->getPosition()->getPosY() + 1);
		if (player->getPosition()->getPosY() == getSizeMap()) {
			player->getPosition()->setPosY(0);
		}
		break;
	case 0x8:
		player->getPosition()->setPosY(player->getPosition()->getPosY() - 1);
		if (player->getPosition()->getPosY() == -1) {
			player->getPosition()->setPosY(getSizeMap() - 1);
		}
		break;
	}

	walkRandomMonster();
	show(player);
}

void Map::show(Player * player) {
	std::string title;

	for (std::size_t x = 0; x <= getSizeMap() - 1; ++x) {
		if (x >= 1) {
			std::cout << std::endl;
		}
		for (std::size_t y = 0; y <= getSizeMap() - 1; ++y) {
			map[x][y] = '.';
			if (x == getSizeMap() - 1) {
			}
			if (player->getPosition()->getPosX() == x && player->getPosition()->getPosY() == y) {
				map[x][y] = '@';
				std::cout << "\033[1;36m"<< map[x][y];
				continue;
			}

			if (player->getPosition()->getPosX() == monster->getPosition()->getPosX() && player->getPosition()->getPosY() == monster->getPosition()->getPosY()) {
				player->setPoints(player->getPoints() + 1);
				for (uint8_t i = 0; i <= 2; ++i) {
					walkRandomMonster();
				}
			}

			if (monster->getPosition()->getPosX() == x && monster->getPosition()->getPosY() == y) {
				map[x][y] = '$';
				std::cout << "\033[1;35m" << map[x][y];
				continue;
			}
			std::cout << "\033[1;34m" << map[x][y];

			title = "GAME ( player : " + player->getName() + ") pontos : " + std::to_string(player->getPoints());
			SetConsoleTitleA(title.c_str());
		}
	}


}

void Map::clear() {
	std::system("cls");
}

void Map::placeMonster() {
	monster->getPosition()->setPosX(static_cast<uint16_t>(1 + (rand() % getSizeMap())));
	monster->getPosition()->setPosY(static_cast<uint16_t>(1 + (rand() % getSizeMap())));
}

void Map::walkRandomMonster() {
	int16_t random = (1 + (rand() % 4));
	switch (random)
	{
	case 1:
		monster->getPosition()->setPosX(monster->getPosition()->getPosX() - 1);
		if (monster->getPosition()->getPosX() == -1) {
			monster->getPosition()->setPosX(getSizeMap() - 1);
		}
		break;
	case 2:
		monster->getPosition()->setPosX(monster->getPosition()->getPosX() + 1);
		if (monster->getPosition()->getPosX() == getSizeMap()) {
			monster->getPosition()->setPosX(0);
		}
		break;
	case 3:
		monster->getPosition()->setPosY(monster->getPosition()->getPosY() + 1);
		if (monster->getPosition()->getPosY() == getSizeMap()) {
			monster->getPosition()->setPosY(0);
		}
		break;
	case 4:
		monster->getPosition()->setPosY(monster->getPosition()->getPosY() - 1);
		if (monster->getPosition()->getPosY() == -1) {
			monster->getPosition()->setPosY(getSizeMap() - 1);
		}
		break;
	default:
		break;
	}

}
