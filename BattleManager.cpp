#include "stdafx.h"
#include "Game.h"
#include "Hero.h"
#include "Spell.h"
#include <iostream>

int main() {
	Hero player("tsveti", 100, 100, 3);
	player.learnSpell(Spell("Slap", 10, 20));
	player.learnSpell(Spell("Kick", 25, 40));
	player.learnSpell(Spell("Eat food", 50, 70));
	Hero villain("phan", 100, 100, 4);
	villain.learnSpell(Spell("Lie", 8, 10));
	villain.learnSpell(Spell("Say OPP", 60, 75));
	villain.learnSpell(Spell("Take picture", 15, 20));
	Game::fight(player, villain);
	return 0;
}

