#ifndef HERO_H_
#define HERO_H_
#include "Spell.h"

class Hero {
private:
	char name[50];
	double hp;
	double mana;
	double damage;
	Spell spellBook[3];
public:

	Hero();
	Hero(char* name, double hp, double mana, double damage);
	bool isDead();
	Hero& learnSpell(Spell spell);
	Hero& attack(Hero& victim);
	Hero& cast(const char* name, Hero& victim);
	Hero& rest();
	const char* getSpellAt(int index) const;
	void print() const;
};


#endif

