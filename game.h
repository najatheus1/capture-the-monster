#pragma once

#include "main.h"
#include "map.h"

class Game {
private:
	Map map;
	KeyBoard * key = new KeyBoard;
public:
	Game() {
	}

	~Game() {

	}

	void start(Player player);
};