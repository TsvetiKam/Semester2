#ifndef SPELL_H_
#define SPELL_H_ 

class Spell {
private:
	char name[50];
	double damage;
	double manaCost;
	void copyStr(char* dest, int n, char* source) {
		int i;
		for (i = 0; i < n; i++)
		{
			dest[i] = source[i];
		}
		dest[i] = '\0';
	}
public:
	Spell(char* name = "", double damage = 0, double manaCost = 0);
	
	friend class Hero;
};

#endif 
