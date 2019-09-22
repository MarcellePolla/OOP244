/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File Account.cpp
// Date July 25th
// Author Marcelle Polla
// Description
// This is the implementation file for the Account module.
// It contains the methods for the Account class.
***********************************************************/
#include <iostream>
#include "Account.h"
using namespace std;
namespace sict{

	Account::Account(double initialBalance){
		if(initialBalance < 0) m_balance = 0;
		else m_balance = initialBalance;
	}

	bool Account::credit(double amountReceived){ 
		if(amountReceived > 0) m_balance += amountReceived;
		return (amountReceived > 0 ? true : false);
	}
	bool Account::debit(double amountReceived){
		if(amountReceived > 0) m_balance -= amountReceived;
		return (amountReceived > 0 ? true : false);
	}
	double Account::balance() const{ return m_balance;}
}