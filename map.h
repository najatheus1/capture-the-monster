#pragma once

#include "main.h"
#include "keyboard.h"
#include "player.h"

class Map {
private:
	int8_t map[16][16];
	KeyBoard * key = new KeyBoard;

public:

	Map();
	~Map();
	void load();
	void move(Player player);
	void show(Player player);
	void clear();
	void placeMonster();
	void walkRandomMonster();

	uint16_t getSizeMap() {
		return static_cast<uint16_t>(sqrt(sizeof(map)));
	}
};
