/***********************************************************
// OOP244 Workshop 7: Derived Classes
// File Hero.cpp
// Date July 15th
// Description
// This is the implementation file for the Hero module.
// It contains the methods for the Hero class.
***********************************************************/
// Headers
#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;
//the sict namespace
namespace sict{
//constructors
	Hero::Hero(){
		setEmpty();
	}

	Hero::Hero(const char name[], const int health, const int attack){
		if(name == nullptr || name[0] == '\0' || health < 0 || attack < 0){
			setEmpty();
		}else{
			strncpy(m_heroName, name, 40);
			m_health = health;
			m_attackStrength = attack;
		}
	}

//performs attack
	void Hero::operator-=(int attack){
		if(attack > 0) m_health -= attack;
		if(!isAlive()) m_health = 0;
	}

//checks if hero is healthy
	bool Hero::isAlive() const{return m_health > 0;}

//returns attack strengh
	int Hero::attackStrength() const{return m_attackStrength;}

//sets hero to empty state
	void Hero::setEmpty(){
		m_heroName[0] = '\0';
		m_health = 0;
		m_attackStrength = 0;
	}

//checks if hero is in empty state
	bool Hero::isEmpty() const{ return ((m_heroName[0] == '\0' && m_health == 0 && m_attackStrength == 0) ? true : false);}
//displays hero
	ostream& Hero::display(ostream& os) const{
		if(isEmpty())
			os << "No hero";
		else
			os << m_heroName;
		return os;
	}

//Helper operators
	std::ostream& operator<<(std::ostream& os, const Hero& hero){
		return hero.display(os);
	}

	const Hero& operator*(const Hero& first, const Hero& second){
		Hero rhs, lhs;
		const Hero* winner;
		rhs = first;
		lhs = second;
		int rounds = 0;
		while(rounds < MAX_ROUNDS &&  rhs.isAlive() && lhs.isAlive()){
			rhs -= lhs.attackStrength();
			lhs -= rhs.attackStrength();
			rounds++;
		}
		if(lhs.isAlive() && !rhs.isAlive()) 
			winner = &second;	
		else	
			winner = &first;

		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}
}
