/***********************************************************
// OOP244 Workshop 4: Constructors and Destructors
// File Passenger.cpp
// Version 1.0
// Date June 4th
// Description
// This is the implementation file for the Passenger module.
// It contains the definitions for the Passenger struct.
// 
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Headers
#include <iostream>
#include <string.h>
#include "Passenger.h"
using namespace std;

//the sict namespace
namespace sict{

//default constructor
	Passenger::Passenger(){
		name[0] = '\0';
		destination[0] = '\0';
	}
//Parameter constructor
	Passenger::Passenger(const char* name, const char* destination){
		if(name == nullptr  || name[0] == '\0' || destination == nullptr || destination[0] == '\0'){
			this->name[0] = '\0';
			this->destination[0] = '\0';
		}else{
			strncpy(this->name, name, 18);
			strncpy(this->destination, destination, 18);
		}
	}
//reports if the object is in a safe empty state
		bool Passenger::isEmpty() const{
			if(this->name[0] == '\0' && this->destination[0] == '\0'){
				return true;
			}else{
				return false;
			}
		}
//displays the contents of the Passenger object
		void Passenger::display() const{
			if(this->isEmpty()){
				cout << "No passenger!" << endl;
			}else{
				cout << this->name << " - " << this->destination << endl;
			}
		}

}
