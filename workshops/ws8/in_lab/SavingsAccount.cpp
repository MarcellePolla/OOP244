/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File SavingsAccount.cpp
// Date July 25th
// Description
// This is the implementation file for the SavingsAccount module.
// It contains the methods for the SavingsAccount class.
***********************************************************/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "Account.h"
using namespace std;
namespace sict{
	SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance){
		if(interest > 0) m_savingsInterest = interest;
		else m_savingsInterest = 0;
	}
	void SavingsAccount::monthEnd(){ 
		credit(balance() * m_savingsInterest);
	}
	void SavingsAccount::display(std::ostream& os) const{
		os << "Account type: Savings" << endl
		<< "Balance: $" << fixed << setprecision(2) << balance() << endl
		<< "Interest Rate (%): " << fixed << setprecision(2) << m_savingsInterest *100 << endl;
	}
}
