#pragma once

#include "main.h"
#include "position.h"

class Item {
private:
	uint16_t id;
	Position* pos = new Position;

public:
	Item(uint16_t id);
	~Item();

	uint16_t getID() {
		return this->id;
	}

	Position* getPosition() {
		return pos;
	}
};