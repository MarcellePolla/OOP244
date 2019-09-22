/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 3.0
// 2019/06/02
// Description
// This is the header file for the CRA_Account module.
// It contains the class definition.
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
//                     
///////////////////////////////////////////////////////////
**********************************************************/
// Header safeguards
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

// sict namespace
namespace sict{

//constant definitions
	const int  max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

//class definition
	class CRA_Account{

		char familyName[max_name_length+1];
		char givenName[max_name_length+1];
		int sin;
		int taxYears[max_yrs];
		double balanceOwed[max_yrs];
		int yearsTaxStored;

	public:
//checks if sin is valid before storing information  
		void set(const char* familyName, const char* givenName, int sin);
//checks if object is in empty state
		bool isEmpty() const;
//displays object information if not empty
		void display() const;
//stores year and balance
		void set(int year, double balance);
	};

}

#endif
