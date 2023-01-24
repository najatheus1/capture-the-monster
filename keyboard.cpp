#include "keyboard.h"


KeyBoard::KeyBoard() {

}

KeyBoard::~KeyBoard() {

}

int8_t KeyBoard::getKeyState() {	
	// bit & bit
	if (GetAsyncKeyState((int)'W')) {
		return this->state = 0x1;
	}
	if (GetAsyncKeyState((int)'S')) {
		return this->state = 0x2;
	}
	if (GetAsyncKeyState((int)'D')) {
		return this->state = 0x4;
	}
	if (GetAsyncKeyState((int)'A')) {
		return this->state = 0x8;
	}
	if (GetAsyncKeyState((int)'Q')) {
		return this->state = 0x10;
	}	
	if (GetAsyncKeyState((int)'E')) {
		return this->state = 0x13;
	}

	this->setKeyState(0x0);

	return 0;
}