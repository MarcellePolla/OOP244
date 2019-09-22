/***********************************************************
// OOP244 Workshop 7: Derived Classes
// File SuperHero.h
// Date July 17th
// Description
// This is the header file for the SuperHero module.
// It contains the prototypes for the SuperHero class.
***********************************************************/
// Header safeguards
#ifndef SICT_SUPERHERO_H__
#define SICT_SUPERHERO_H__
#include "Hero.h"
// sict namespace
namespace sict{
	class SuperHero : public Hero {
		int m_attackBonus;
		int m_defendStrength;
		bool isEmpty();
	public:
		SuperHero();
		SuperHero(const char name[], const int health, const int attack, int bonus, int defense);
		int attackStrength() const;
		int defend() const;	
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif
