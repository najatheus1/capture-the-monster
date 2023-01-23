#pragma once

#include "main.h"
#include "position.h"

class Monster {
private:
	std::string name;
	uint16_t health;
	Position* pos = new Position;
public:

	Monster(std::string name, uint16_t health);
	~Monster();

	Position* getPosition() {
		return pos;
	}
};
