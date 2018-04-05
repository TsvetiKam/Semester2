#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Hero.h"


Hero::Hero() {
	strcpy_s(name, "");
	hp = 0;
	mana = 0;
	damage = 0;
}

Hero::Hero(char * name, double hp, double mana, double damage) {
	strcpy_s(this->name, strlen(name) + 1, name);
	this->hp = hp;
	this->mana = mana;
	this->damage = damage;

}

bool Hero::isDead() {
	return this->hp <= 0;
}

Hero & Hero::learnSpell(Spell spell) {
	int index = -1;
	for (int i = 2; i >= 0; i--) {
		if (strcmp(this->spellBook[i].name, "") == 0) {
			index = i;
		}
	}
	if (index != -1) {
		strcpy_s(this->spellBook[index].name, strlen(spell.name) + 1, spell.name);
		this->spellBook[index].damage = spell.damage;
		this->spellBook[index].manaCost = spell.manaCost;
	}
	return *this;
}

Hero & Hero::attack(Hero & victim) {
	if (!victim.isDead()) {
		victim.hp -= this->damage;
		std::cout << name << " attacked " << victim.name << " for " << this->damage << " damage!\n";
	}
	return *this;
}

Hero & Hero::cast(const char * spellName, Hero & victim) {
	if (!victim.isDead()) {
		for (int i = 0; i < 3; i++) {
			if (strcmp(this->spellBook[i].name, spellName) == 0) {
				if (this->mana >= this->spellBook[i].manaCost) {
					victim.hp -= this->spellBook[i].damage;
					this->mana -= this->spellBook[i].manaCost;

					std::cout << name << " casted " << spellName << " at " << victim.name << " for " 
						<< this->spellBook[i].damage << " damage!\n";
				}
				else {
					std::cout << "Not enough mana for " << spellName << std::endl;
				}
			}
		}
	}

	return *this;
}

Hero & Hero::rest() {
	hp += (100 * 0.05);
	mana += (100 * 0.05);
	std::cout << name << " regained " << (100 * 0.05) << " hp and " << (100 * 0.05) << " mana!\n";
	return *this;
}

const char * Hero::getSpellAt(int index) const {
	if (spellBook[index].name != nullptr) {
		return spellBook[index].name;
	}
}

void Hero::print() const {
	std::cout << name << " damage: " << damage << ", hp: " << hp << ", mana: "<< mana << std::endl;
}
