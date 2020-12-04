#include "Renderer.h"
#include <iostream>

void ObserverTextRender::render(const Game& game)const{
	int mult=0;
	std::cout << "╔";
	for (int i = 0; i < game.getMap().getRowSize(0)-1; i++)
	{
		std::cout << "══";
	}
	std::cout << "╗" << std::endl;
	for (int i = 0; i < game.getMap().getMapSize(); i++) {
		std::cout << "║";
		for (int j = 0; j < game.getMap().getRowSize(i); j++) {
			switch (game.getMap().getMapField(i, j)) {
			case 'H':
				std::cout << "┣┫";
				break;
			case '#':
				std::cout << "██";
				break;
			case 'm':
				mult = 0;
				for (const auto& monster : game.getMonster())
				{
					if (monster.getUnitPositionX() == i && monster.getUnitPositionY() == j)
					{
						mult++;
					}
				}
				if (mult > 1) {
					std::cout << "MM";
				}
				else {
					std::cout << "M░";
				}
				break;
			case ' ':
				std::cout << "░░";
				break;
			case '1':
				std::cout << "M░";
				break;
			case '2':
				std::cout << "M░";
				break;
			case '3':
				std::cout << "M░";
				break;
			}
		}
		std::cout << "║\n";
	}
	std::cout << "╚";
	for (int i = 0; i < game.getMap().getRowSize(0)-1; i++)
	{
		std::cout << "══";
	}
	std::cout << "╝" << std::endl;
}

void HeroTextRender::render(const Game& game)const{
	int mult=0;
	std::cout<<"╔";
	for (int j = (game.getHero().getUnitPositionY()-game.getHero().getLightRadius()<0 ? 0: game.getHero().getUnitPositionY()-game.getHero().getLightRadius()); j <= (game.getHero().getUnitPositionY()+game.getHero().getLightRadius()>=game.getGameMapRowSize(0)-1 ? game.getGameMapRowSize(0)-2:game.getHero().getUnitPositionY()+game.getHero().getLightRadius()); j++)
	{
		std::cout << "══";
	}
	std::cout << "╗" << std::endl;
	for (int i =(game.getHero().getUnitPositionX()-game.getHero().getLightRadius()<0 ? 0: game.getHero().getUnitPositionX()-game.getHero().getLightRadius());i<=(game.getHero().getUnitPositionX()+game.getHero().getLightRadius()>=game.getGameMapSize()? game.getGameMapSize()-1:game.getHero().getUnitPositionX()+game.getHero().getLightRadius()); i++) {
		std::cout << "║";
		for (int j = (game.getHero().getUnitPositionY()-game.getHero().getLightRadius()<0 ? 0: game.getHero().getUnitPositionY()-game.getHero().getLightRadius()); j <= (game.getHero().getUnitPositionY()+game.getHero().getLightRadius()>=game.getGameMapRowSize(i) ? game.getGameMapRowSize(i)-1:game.getHero().getUnitPositionY()+game.getHero().getLightRadius()); j++){
			switch (game.getMap().getMapField(i, j)) {
			case 'H':
				std::cout << "┣┫";
				break;
			case '#':
				std::cout << "██";
				break;
			case 'm':
				mult = 0;
				for (const auto& monster : game.getMonster())
				{
					if (monster.getUnitPositionX() == i && monster.getUnitPositionY() == j)
					{
						mult++;
					}
				}
				if (mult > 1) {
					std::cout << "MM";
				}
				else {
					std::cout << "M░";
				}
				break;
			case ' ':
				std::cout << "░░";
				break;
			case '1':
				std::cout << "M░";
				break;
			case '2':
				std::cout << "M░";
				break;
			case '3':
				std::cout << "M░";
				break;
			}
		}
		std::cout << "║\n";
	}
	std::cout << "╚";
	for (int j = (game.getHero().getUnitPositionY()-game.getHero().getLightRadius()<0 ? 0: game.getHero().getUnitPositionY()-game.getHero().getLightRadius()); j <= (game.getHero().getUnitPositionY()+game.getHero().getLightRadius()>=game.getGameMapRowSize(0)-1 ? game.getGameMapRowSize(0)-2:game.getHero().getUnitPositionY()+game.getHero().getLightRadius()); j++)
	{
		std::cout << "══";
	}
	std::cout << "╝" << std::endl;
}

//std::ostream& TextRender::setOutputStream(std::ostream& output){}