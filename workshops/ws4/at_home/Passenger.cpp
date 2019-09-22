/***********************************************************
// OOP244 Workshop 4: Constructors and Destructors
// File Passenger.cpp
// Version 1.0
// Date June 6th
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
#include <iomanip>
#include <string.h>
#include "Passenger.h"
using namespace std;

//the sict namespace
namespace sict{

//default constructor
	Passenger::Passenger(){
		passengerName[0] = '\0';
		destination[0] = '\0';
		depDay = 0;
		depMonth = 0;
		depDay = 0;
	}
//Parameter constructor
	Passenger::Passenger(const char* name, const char* dest){
		if(name == nullptr  || name[0] == '\0' || dest == nullptr || dest[0] == '\0'){
			passengerName[0] = '\0';
			destination[0] = '\0';
		}else{
			strncpy(passengerName, name, 18);
			strncpy(destination, dest, 18);
			depYear = 2019;
			depMonth = 10;
			depDay = 1;
		}
	}

//Parameter constructor
	Passenger::Passenger(const char* name, const char* dest, int year, int month, int day){
		bool nameIsValid = true;
		bool destinationIsValid = true;
		bool yearIsValid = true;
		bool monthIsValid = true;
		bool dayIsValid = true;
		if(name == nullptr  || name[0] == '\0'){
			nameIsValid=false;
		}
		if(dest == nullptr || dest[0] == '\0'){
			destinationIsValid = false;
		}
		if(year < 2019 || year > 2021){
			yearIsValid=false;
		}
		if(month < 1 || month >12){
			monthIsValid=false;
		}
		if(day < 1 || day > 31){
			dayIsValid=false;
		}

		if(nameIsValid && destinationIsValid && yearIsValid && monthIsValid && dayIsValid){
			strncpy(passengerName, name, 18);
			strncpy(destination, dest, 18);
			depYear = year;
			depMonth = month;
			depDay = day;
		}else{
			passengerName[0] = '\0';
			destination[0] = '\0';
			depYear = 0;
			depMonth = 0;
			depDay = 0;
		}

	}
//reports if the object is in a safe empty state
		bool Passenger::isEmpty() const{
			if(passengerName[0] == '\0' && destination[0] == '\0'){
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
				cout << passengerName << " - " << destination << " on "
				<< depYear << "/" 
				<< setw(2) << setfill('0') << depMonth << "/" 
				<< setw(2) << setfill('0') << depDay << endl;
			}
		}
//returns address of passenger name
		const char* Passenger::name() const{
			return passengerName;
		}
//checks if passengers can travel together
		bool Passenger::canTravelWith(const Passenger&) const{
			if(this->destination == destination && this->depDay == depDay && this->depMonth == depMonth && this->depYear == depYear){
				return true;
			}else
				return false;
		}
}
