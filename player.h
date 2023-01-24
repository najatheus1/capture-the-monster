#pragma once

#include "main.h"
#include "position.h"
#include "keyboard.h"

class Player {
private:
	std::string name;
	KeyBoard key;
	Position * pos = new Position;
	int point = 0;
	uint32_t level = 0;

public:
	Player(std::string name, uint8_t x, uint8_t y);
	~Player();

	Position * getPosition() {
		return pos;
	}

	std::string getName() {
		return name;
	}

	int getPoints() {
		return point;
	}

	void setPoints(int point) {
		this->point = point;
	}

	uint32_t getLevel() {
		return this->level;
	}

	void setLevel(uint32_t level) {
		this->level = level;
	}
};