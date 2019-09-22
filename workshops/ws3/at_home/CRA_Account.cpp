/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 3.0
// 2019/05/30
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
#include <cmath>
#include "CRA_Account.h"
using namespace std;

//the sict namespace
namespace sict{
//checks if sin is valid before storing information  
		void CRA_Account::set(const char* familyName, const char* givenName, int sin){

			bool valid = false;

			if(sin>= min_sin && sin<= max_sin){
				int digit =0;
				int checkDigit=0;
				int odd = 0;
				int total = 0;
				int highest = 0;
				int number = 0;
				int even = 0;
				number = sin;
				
				for(int i=0; i<= 8; i++){

					digit = number % 10;
					number = number / 10;

					if(i==0){
						checkDigit = digit;
					}
					else if( i % 2 != 0){
						odd += ((digit * 2) % 10) + ((digit * 2) /10);
					}
					else if(i % 2 == 0){
						even = even + digit;
					}
		
					total = odd + even;
				}


	 			if(total % 10 != 0){
	 				highest = ((total/10) * 10) +10;
	 			}
	 			
	 			total = highest - total;
	 			if(total == checkDigit){
	 				valid = true;
	 			}
			}

			if(valid == true && familyName[0] != '\0' && givenName[0] != '\0'){
				strncpy(this->familyName, familyName, max_name_length);
				this->familyName[max_name_length]= '\0';
				strncpy(this->givenName,givenName,max_name_length);
				this->givenName[max_name_length]= '\0';
				this->sin = sin;
				this->yearsTaxStored = 0;
			}else{
//set to empty state
				this ->familyName[0] = '\0';
				this ->givenName[0] = '\0';
				this ->sin = 0;
				
			}
		}
//checks if object is in empty state
		bool CRA_Account::isEmpty() const{
			if(this->sin==0 && this->givenName[0]=='\0' && this->familyName[0]=='\0')
				return true;
			else
				return false;
			
		}
//displays object information if not empty
		void CRA_Account::display() const{
			if(this->isEmpty()==false){
				cout << "Family Name: " << this->familyName << endl;
				cout << "Given Name : " << this->givenName << endl;
				cout << "CRA Account: " << this->sin <<endl;
				for(int i=0 ; i< this->yearsTaxStored; i++){
					if(this->balanceOwed[i] > 2){
						cout << "Year ("<< this->taxYears[i] << ") balance owing: " << this->balanceOwed[i]<< endl;
					}else if(this-> balanceOwed[i] < -2){
						cout << "Year (" << this->taxYears[i] << ") refund due: " ;
						cout.precision(2); 
						cout << fixed << abs(this->balanceOwed[i]) << endl;
					}else{
						cout << "Year (" << this->taxYears[i] << ") No balance owing or refund due!" << endl;
					}
				}
			}else{
				cout << "Account object is empty!" << endl;
			}
		}
//stores year and balance
		void CRA_Account::set(int year, double balance){
			if( this->isEmpty() == false && yearsTaxStored < max_yrs){
				this->balanceOwed[yearsTaxStored] = balance;
				this->taxYears[yearsTaxStored]=year;
				yearsTaxStored++;
			}
		}
}
