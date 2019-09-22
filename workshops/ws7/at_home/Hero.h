/***********************************************************
// OOP244 Workshop 7: Derived Classes
// File Hero.h
// Date July 17th
// Description
// This is the header file for the Hero module.
// It contains the prototypes for the Hero class.
***********************************************************/
// Header safeguards
#ifndef SICT_HERO_H__
#define SICT_HERO_H__
#include <iostream>
// sict namespace
namespace sict{
	#define MAX_ROUNDS 100
	class Hero
	{
		char m_heroName[41];
		int m_health;
		int m_attackStrength;
		void setEmpty();
	public:
		Hero();
		Hero(const char name[], const int health, const int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		std::ostream& display(std::ostream& os = std::cout)const;
	};

	std::ostream& operator<<(std::ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif
