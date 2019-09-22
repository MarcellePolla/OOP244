/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File iAccount.h
// Date July 25th
// Author Marcelle Polla
// Description
// This is the abstract base class for the Account hierarchy.
// It contains the pure virtual member functions for the 
// iAccount interface.
***********************************************************/
#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__
#include <iostream>
namespace sict{
	class iAccount{
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char*, double);
}
#endif