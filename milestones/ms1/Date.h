/***********************************************************
// OOP244 Aid Management Application : Milestone 1
// File Date.h
// Date July 10th
// Description
// This is the header file for the Date module.
// It contains the prototypes for the Date class.
***********************************************************/
#ifndef AID_DATE_H__
#define AID_DATE_H__

#include <iostream>
#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5


namespace aid{
	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date{
		int year;
		int month;
		int dayOfMonth;
		int comparator;
		int errorState;
		void errCode(int errorCode);
		int mdays(int year, int mon) const;
		int isValid(int y, int m, int d);
	public:
		Date();
		Date(int year, int month, int day);
		bool operator==(const Date &rhs) const;
		bool operator!=(const Date &rhs) const;
		bool operator<(const Date &rhs) const;
		bool operator>(const Date &rhs) const;
		bool operator<=(const Date &rhs) const;
		bool operator>=(const Date &rhs) const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
		std::istream& operator>>(std::istream& is, Date& d);
		std::ostream& operator<<(std::ostream& os, const Date& d);

}

#endif
