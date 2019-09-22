/***********************************************************
// OOP244 Aid Management Application : Milestone 5
// File Date.cpp
// Date Aug 3rd
// Description
// This is the implementation file for the Date module.
// It contains the prototypes for the Date class.
***********************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Date.h"
using namespace std;
namespace aid{

//constructors
	Date::Date(){
		errorState = NO_ERROR;
		year = 0;
		month = 0;
		dayOfMonth = 0;
		comparator = 0;
	}

	Date::Date(int y, int m, int d){
		
		 if(isValid(y,m,d)){
			year = y;
			month = m;
			dayOfMonth = d;
			comparator = (y*372) + (m*31) + d;
		}else{
			*this = Date();
		}
	}

//date validation
	bool Date::isValid(int y, int m, int d){
		bool valid = false;
		int comparatorCheck = (y*372) + (m*31) + d;
		if(y <= max_year && y >= min_year){
			if(m <= 12 && m >= 1){
				if(d <= mdays(m, y) || d >= 1){
					if(comparatorCheck >= min_date)	
						valid = true;
					else
						errorState = PAST_ERROR;
				}else
					errorState = DAY_ERROR;
			}else
				errorState = MON_ERROR;
		}else
			errorState = YEAR_ERROR;
		return valid;
	}
//sets error code
	void Date::errCode(int errorCode){
		errorState = errorCode;
	}
//returns days in the month
	int Date::mdays(int year, int mon) const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
//comparison overloads
	bool Date::operator==(const Date &rhs) const{
		return (!bad() ? (comparator == rhs.comparator) : false);
	}

	bool Date::operator!=(const Date &rhs) const{
		return (!bad() ? (comparator != rhs.comparator) : false);
	}

	bool Date::operator<(const Date &rhs) const{
		return (!bad() ? (comparator < rhs.comparator) : false);
	}

	bool Date::operator>(const Date &rhs) const{
		return (!bad() ? (comparator > rhs.comparator) : false);
	}

	bool Date::operator<=(const Date &rhs) const{
		return (!bad() ? (comparator <= rhs.comparator) : false);
	}
	bool Date::operator>=(const Date &rhs) const{
		return (!bad() ? (comparator >= rhs.comparator) : false);
	}
//gets error code
	int Date::errCode() const{
		return errorState;
	}

//checks for error code
	bool Date::bad() const{
		return errCode() != 0;
	}
//gets client input
	std::istream& Date::read(std::istream& istr){

		char ig;
		int d, m, y;

		istr >> y >> ig >> m >> ig >> d;

		if(!istr.fail()){
			if(isValid(y, m, d)){
				year = y;
				month = m;
				dayOfMonth = d;
			}
		}else
			errorState = CIN_FAILED;
		return istr;
	}

//outputs date
	std::ostream& Date::write(std::ostream& ostr) const{
		return ostr << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << dayOfMonth;
	}

//input operator overload
	std::istream& operator>>(std::istream& is, Date& d){
		d.read(is);
		return is;
	}
//output operator overload
	std::ostream& operator<<(std::ostream& os, const Date& d){
		d.write(os);
		return os;
	}

}
