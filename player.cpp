#include "player.h"

Player::Player(std::string name, uint8_t x, uint8_t y) {
	this->name = name;
	pos->setPosX(x);
	pos->setPosY(y);
}

Player::~Player() {

}
