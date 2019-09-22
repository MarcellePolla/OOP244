/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 26th
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

	//Calculates the total number of people in all kingdoms and displays kingdom information and total population

	void display(const struct Kingdom* kingdoms, int size){

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		int sumPop=0;
		for(int i = size -1; i >= 0; i--){
			cout << i +1 << ". ";
			display(kingdoms[i]);
			sumPop= sumPop+kingdoms[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << sumPop << endl;
		cout << "------------------------------" << endl;
	}

}

    