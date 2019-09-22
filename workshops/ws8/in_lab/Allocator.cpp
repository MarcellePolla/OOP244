/***********************************************************
// OOP244 Workshop 8: Virtual Functions
// File Allocator.cpp
// Date July 25th
// Author Marcelle Polla
// Description
// This is the Allocator implementation file for the Account 
// module. It contains the definitions for the Account class.
***********************************************************/
#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;
namespace sict{
	const double interest_rate = 0.05;

	iAccount* CreateAccount(const char* accountType, double initialBalance){

		Account* account = nullptr;
		if(accountType[0] == 'S'){
			account = new SavingsAccount(initialBalance, interest_rate);
		}
		return account;
	}
}