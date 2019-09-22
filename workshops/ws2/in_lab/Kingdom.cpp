/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 23rd
// Author Marcelle Polla
// Description
// This is the implementation file for the Kingdom module.
// It contains the function definitions for the Kingdom struct.
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;


//the sict namespace
namespace sict{

	//Displays Kingdom name and population 
	void display(const struct Kingdom& king){
		cout << king.m_name << ", population " << king.m_population << endl;
	}
}

    