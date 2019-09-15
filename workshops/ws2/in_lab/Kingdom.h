/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date May 23rd
// Author Marcelle Polla
// Description
// This is the header file for the Kingdom module.
// It contains the definitions and prototypes for the
// Kingdom struct.
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// sict namespace
namespace sict{

// Structure Kingdom definition
	struct Kingdom{

		char m_name[32];
		int m_population;
	};

//Prototype//
//Displays kingdom name and population
	void display(const struct Kingdom& king);

}

#endif