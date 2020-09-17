#include "units.h"
#include "games.h"
#include <iostream>

void listUnitAttributes(Unit& unit1,Unit& unit2){	
	std::cout << unit1.getName() << ":HP:" << unit1.getHp() << ",DMG:" << unit1.getDamage() << std::endl;
	std::cout << unit2.getName() << ":HP:" <<unit2.getHp() << ",DMG:" <<unit2.getDamage() << std::endl;
}
void damageLog(Unit& unit1, Unit& unit2) {
	if (unit1.getHp() != 0){
		unit1.dealDamageTo(unit2);
		std::cout << unit1.getName() << "->" << unit2.getName() << std::endl;
	}
	else {
		std::cout << unit1.getName() << " died." << unit2.getName() << " wins." << std::endl;
	}
}

void gamePlay(Unit& unit1, Unit& unit2){	
	while(Fight::endGame(unit1,unit2)){
		//Az első unit támad
		listUnitAttributes(unit1, unit2);	
		damageLog(unit1, unit2);
		//A második unit támad
		listUnitAttributes(unit1, unit2);
		damageLog(unit2, unit1);
	}
}
int main(int argc,char* argv[])
{
	if (argc !=7){
		//Tesztelésre
		/*Unit unit1("Maple",150,10),unit2("Sally",45,30);
		gamePlay(unit1, unit2);*/
		std::cout << "A proper input example: ./a.out Maple 150 10 Sally 45 30" << std::endl;
	}
	else{
		Unit unit1(argv[1], std::stoi(argv[2]), std::stoi(argv[3])), unit2(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
		gamePlay(unit1, unit2);
	}
	std::cin.get();
}