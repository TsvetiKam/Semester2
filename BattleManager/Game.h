#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "Hero.h"
#include <ctime>
#include "stdlib.h"
namespace Game {
	void AITurn(Hero& AI, Hero& player) {
		srand(time(NULL));
		int choice = rand() % 4 + 1;
		switch (choice) {
			case 1:
				AI.attack(player); break;
			case 2:
				AI.rest(); break;
			case 3:
				AI.cast(AI.getSpellAt(0), player); break;
			case 4:
				AI.cast(AI.getSpellAt(1), player); break;
			case 5:
				AI.cast(AI.getSpellAt(2), player); break;
			default:
				AI.rest(); break;
		}
	}
	void playerTurn(Hero& player, Hero& victim) {
		std::cout << "Decide what to do:\n";
		std::cout << "1:Attack\n2:Rest\n";
		for (int i = 3; i < 6; i++) {
			std::cout << i << ":cast " << player.getSpellAt(i - 3) << std::endl;
		}
		int choice;
		std::cin >> choice; // danger
		std::cout << std::endl;
		switch (choice) {
			case 1:
				player.attack(victim); break;
			case 2:
				player.rest(); break;
			case 3:
				player.cast(player.getSpellAt(0), victim); break;
			case 4:
				player.cast(player.getSpellAt(1), victim); break;
			case 5:
				player.cast(player.getSpellAt(2), victim); break;
			default:
				player.rest(); break;
		}
	}
	void fight(Hero& player, Hero& victim) {
		player.print();
		victim.print();
		while (!player.isDead() && !victim.isDead()) {
			playerTurn(player, victim);
			if (!victim.isDead()) {
				AITurn(victim, player);
			}
			std::cout << std::endl;
			player.print();
			victim.print();
		}
		if (player.isDead()) {
			std::cout << "You died! :(\n";
		}
		else {
			std::cout << "You won!\n";
		}
	}
};

#endif