/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File SavingsAccount.h
// Date July 25th
// Description
// This is the header file for the SavingsAccount module.
// It contains the prototypes for the SavingsAccount class.
***********************************************************/
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iostream>
#include "Account.h"
namespace sict{
	class SavingsAccount : public Account{
		double m_savingsInterest;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
