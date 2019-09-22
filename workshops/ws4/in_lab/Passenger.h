
/***********************************************************
// OOP244 Workshop 4: Constructors and Destructors
// File Passenger.h
// Version 1.0
// Date June 4th
// Author Marcelle Polla
// Description
// This is the header file for the Passenger module.
// It contains the prototypes for the Passenger struct.
// 
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Header safeguards
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// sict namespace
namespace sict{
//class Passanger definition
	class Passenger{
		char name[19];
		char destination[19];

	public:
//Constructors
		Passenger();
		Passenger(const char* name, const char* destination);
//reports if the object is in a safe empty state
		bool isEmpty() const;
//displays the contents of the Passenger object
		void display() const;
	};
}

#endif