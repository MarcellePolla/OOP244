/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File Allocator.cpp
// Date July 25th
// Description
// This is the Allocator implementation file for the Account 
// module. It contains the definitions for the Account class.
***********************************************************/
#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"
using namespace std;
namespace sict{
	const double interest_rate = 0.05;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;

	iAccount* CreateAccount(const char* accountType, double initialBalance){
		Account* account = nullptr;
		if(accountType[0] == 'S'){
			account = new SavingsAccount(initialBalance, interest_rate);
		}
		if(accountType[0] == 'C'){
			account = new ChequingAccount(initialBalance, transaction_fee, monthly_fee);
		}
		return account;
	}
}
