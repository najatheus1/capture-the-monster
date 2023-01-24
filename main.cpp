#include "main.h"
#include "game.h"


int main(void)
{
	SetConsoleTitleA("GAME");
	Game game;
	Map map;
	std::string name_;
	std::cout << "Digite um nome para seu personagem" << std::endl;  
	std::cin >> name_;
	Player player(name_, static_cast<uint8_t>(1 + rand() % map.getSizeMap()), static_cast<uint8_t>(1 + rand() % map.getSizeMap()));
	std::system("cls");
	std::cout << "Ande com seu personagem!" << std::endl;
	game.start(&player);
	return 0;
}
