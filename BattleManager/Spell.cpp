#include "stdafx.h"
#include "Spell.h"
#include <cstring>



Spell::Spell(char * name, double damage, double manaCost) {
	copyStr(this->name, strlen(name) + 1, name);
	//strcpy_s(this->name, strlen(name) + 1, name);
	this->damage = damage;
	this->manaCost = manaCost;
}
