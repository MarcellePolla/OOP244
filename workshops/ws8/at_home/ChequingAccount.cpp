/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File ChequingAccount.cpp
// Date July 25th
// Author Marcelle Polla
// Description
// This is the implementation file for the ChequingAccount module.
// It contains the methods for the ChequingAccount class.
***********************************************************/
#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
#include "Account.h"
using namespace std;
namespace sict{
	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthEndFee) : Account(balance){
		(transactionFee > 0 ? m_transactionFee = transactionFee : m_transactionFee = 0.0);
		(monthEndFee > 0 ? m_monthEndFee = monthEndFee : m_monthEndFee = 0.0);
	}
	bool ChequingAccount::credit(double amountReceived){ 
		if(Account::credit(amountReceived)) Account::debit(m_transactionFee);
		return amountReceived > 0;
	}
	bool ChequingAccount::debit(double amountReceived){
		if(Account::debit(amountReceived)) Account::debit(m_transactionFee);
		return amountReceived > 0;	
	}

	void ChequingAccount::monthEnd(){ 
		Account::debit(m_monthEndFee);
	}
	void ChequingAccount::display(std::ostream& os) const{
		os << "Account type: Chequing" << endl
		<< "Balance: $" << fixed << setprecision(2) << balance() << endl
		<< "Per Transaction Fee: " << fixed << setprecision(2) << m_transactionFee << endl
		<< "Monthly Fee: " << fixed << setprecision(2) << m_monthEndFee << endl;
	}
}