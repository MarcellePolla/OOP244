/***********************************************************
// OOP244 Aid Management Application : Milestone 1
// File Date.cpp
// Date July 10th
// Description
// This is the implementation file for the Date module.
// It contains the prototypes for the Date class.
***********************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;
namespace aid{

//constructors
	Date::Date(){
		errCode(0);
		year = 0;
		month = 0;
		dayOfMonth = 0;
		comparator = 0;
	}

	Date::Date(int y, int m, int d){
		errCode(isValid(y, m, d));
		 if(errCode()==0){
			year = y;
			month = m;
			dayOfMonth = d;
			comparator = (y*372) + (m*31) + d;
			errCode(0);
		}else{
			*this = Date();
		}
	}

//date validation
	int Date::isValid(int y, int m, int d){
		int ret;
		int comparatorCheck = (y*372) + (m*31) + d;
			if(y >= min_year && y <= max_year){
				if(m >=1 && m <= 12){
					if(d >= 1 && d <= mdays(y,m)){
						if(comparatorCheck >= min_date){
							ret = 0;
						}else
							ret = 5;
					}else
						ret = 2;
				}else
					ret = 3;
			}else
				ret = 4;
		return ret;
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

		char yStr[5], mStr[3], dStr[3];
		istr.getline(yStr,5,'/');
		istr.getline(mStr,3,'/');
		istr.get(dStr,3,'\n');

		if(istr.fail()){
			errCode(1);
		}else{
			int y = atoi(yStr);
			int m = atoi(mStr);
			int d = atoi(dStr);

			errCode(isValid(y, m, d));
		 	if(errCode()==0){
				year = y;
				month = m;
				dayOfMonth = d;
				comparator = (y*372) + (m*31) + d;
			}
		}
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
