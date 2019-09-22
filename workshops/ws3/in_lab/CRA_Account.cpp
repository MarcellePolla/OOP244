/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 3.0
// 2019/05/30
// Marcelle Polla
// Description
// This is the implementation file for the CRA_Account module.
// It validades SIN numbers.
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
//                     
///////////////////////////////////////////////////////////
**********************************************************/
#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

//the sict namespace
namespace sict{
//checks if sin is valid before storing information  
		void CRA_Account::set(const char* familyName, const char* givenName, int sin){
			if(sin>= min_sin && sin<= max_sin){
				strncpy(familyN, familyName, max_name_length);
				familyN[max_name_length]='\0';
				strncpy(givenN,givenName,max_name_length);
				givenN[max_name_length]='\0';
				sinNumber = sin;

			}
			else{
//set to empty state
				familyN[0] = '\0';
				givenN[0] = '\0';
				sinNumber = 0;
				
			}

		}
//checks if object is in empty state
		bool CRA_Account::isEmpty() const{
			if(sinNumber==0 && givenN[max_name_length]=='\0' && familyN[max_name_length]=='\0'){
				return true;
			}
			else
				return false;
			
		}
//displays object information if not empty
		void CRA_Account::display() const{
			if(this->isEmpty()==false){
				cout << "Family Name: " << familyN << endl;
				cout << "Given Name : " << givenN << endl;
				cout << "CRA Account: " << sinNumber <<endl;
			}else{
				cout << "Account object is empty!" << endl;
			}
		}
}