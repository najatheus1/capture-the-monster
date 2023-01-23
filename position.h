#pragma once

#include "main.h"

class Position {
private:
	int16_t x;
	int16_t y;

public:
	Position();
	~Position();

	int16_t getPosX() {
		return x;
	}

	void setPosX(int16_t new_pos_x) {
		x = new_pos_x;
	}

	int16_t getPosY() {
		return y;
	}

	void setPosY(int16_t new_pos_y) {
		y = new_pos_y;
	}
};
