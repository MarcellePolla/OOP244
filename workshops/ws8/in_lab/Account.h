/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File Account.h
// Date July 25th
// Author Marcelle Polla
// Description
// This is the header file for the Account module.
// It contains the prototypes for the Account class.
***********************************************************/
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
#include "iAccount.h"
namespace sict{
	class Account : public iAccount{
		double m_balance;
	protected:
		double balance() const;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	};
}
#endif