/***********************************************************
// OOP244 Workshop 7: Derived Classes
// File SuperHero.cpp
// Date July 15th
// Description
// This is the implementation file for the SuperHero module.
// It contains the methods for the SuperHero class.
***********************************************************/
// Headers
#include <iostream>
#include "SuperHero.h"
#include "Hero.h"
using namespace std;
//the sict namespace
namespace sict{
//constructors
	SuperHero::SuperHero(){
		m_attackBonus = 0;
		m_defendStrength = 0;
	}

	SuperHero::SuperHero(const char name[], const int health, const int attack, int bonus, int defense) : Hero(name, health, attack){
		if(bonus) m_attackBonus = bonus;
		if(defense) m_defendStrength = defense;
	}

//checks whether superhero is in empty state
	bool SuperHero::isEmpty(){return (Hero::isEmpty() && m_attackBonus == 0 && m_defendStrength == 0);}

//returns attack strength + bonus
	int SuperHero::attackStrength() const{return Hero::attackStrength() + m_attackBonus;}

//returns superhero defense
	int SuperHero::defend() const{return m_defendStrength;}

//battles and returns winner
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
		SuperHero rhs, lhs;
		const SuperHero* winner;
		rhs = first;
		lhs = second;
		int rounds = 0;
		while(rounds < MAX_ROUNDS &&  rhs.isAlive() && lhs.isAlive()){
			rhs -= (lhs.attackStrength() - rhs.defend());
			lhs -= (rhs.attackStrength() - lhs.defend());
			rounds++;
		}
		if(lhs.isAlive() && !rhs.isAlive()) 
			winner = &second;	
		else	
			winner = &first;
		cout << "Super Fight! " << first << " vs " << second << " : Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}
}
