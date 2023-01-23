#pragma once

#include "main.h"


class KeyBoard {
private:
	int8_t state = 0;
public:
	KeyBoard();
	~KeyBoard();

	int8_t getKeyState();
	void setKeyState(int8_t state_) {
		this->state = state_;
	}
};
