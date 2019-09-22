/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File ChequingAccount.h
// Date July 25th
// Author Marcelle Polla
// Description
// This is the header file for the ChequingAccount module.
// It contains the prototypes for the ChequingAccount class.
***********************************************************/
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__
#include <iostream>
#include "Account.h"
namespace sict{
	class ChequingAccount : public Account{
		double m_transactionFee;
		double m_monthEndFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif