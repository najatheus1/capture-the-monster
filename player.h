#pragma once

#include "main.h"
#include "position.h"
#include "keyboard.h"

class Player {
private:
	std::string name;
	KeyBoard key;
	Position * pos = new Position;

public:
	Player(std::string name, uint8_t x, uint8_t y);
	~Player();

	Position * getPosition() {
		return pos;
	}

	std::string getName() {
		return name;
	}
};