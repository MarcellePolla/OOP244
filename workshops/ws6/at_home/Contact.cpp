/***********************************************************
// OOP244 Workshop 6: Class with a resource
// File Contact.cpp
// Date July 13th
// Author Marcelle Polla
// Description
// This is the implementation file for the Contact module.
// It contains the methods for the Contact class.
***********************************************************/
// Headers
#include <iostream>
#include <string.h>
#include "Contact.h"
using namespace std;
//the sict namespace
namespace sict{

	//Constructors
		Contact::Contact(){
			contactName[0] = '\0';
			phoneNumbers = nullptr;
			phoneNumberCt = 0;
		}

		Contact::Contact(const char *name, const long long* numbers, int ct){
			if(name != nullptr && name[0] != '\0'){
				strncpy(contactName, name, MAX_CHAR);
			}else{
				contactName[0] = '\0';
			}

			phoneNumberCt = 0;
			if(numbers != nullptr && ct > 0){
				for(int i = 0 ; i < ct; i++){
					if(isValid(numbers[i])){
						phoneNumberCt++;
					}
				}
				phoneNumbers = new long long[phoneNumberCt];
				int validCt = 0;
				for(int i = 0 ; i < ct; i++){
					if (isValid(numbers[i])){
						phoneNumbers[validCt] = numbers[i];
						validCt++;
					}
				}
			}else{
				phoneNumbers = nullptr;
				phoneNumberCt = 0;
			}
		}

		Contact::Contact(const Contact &contact):phoneNumbers(nullptr){
			*this = contact;
		}


	//Desctructor
		Contact::~Contact(){
			delete [] phoneNumbers;
		}
	//operator overloads	

		Contact& Contact::operator=(const Contact& contact){
			if(this != &contact){
				phoneNumberCt = contact.phoneNumberCt;
				strncpy(contactName, contact.contactName, MAX_CHAR);

				delete [] phoneNumbers;

				if(contact.phoneNumbers != nullptr){
					phoneNumbers = new long long [contact.phoneNumberCt];

					for(int i = 0; i < contact.phoneNumberCt ; i++){
						phoneNumbers[i] = contact.phoneNumbers[i];
					}
				}else
					phoneNumbers = nullptr;
			}
			return *this;
		}

		Contact& Contact::operator+=(const long long number){
			
			if(isValid(number)){

				Contact temp = *this;

				delete [] phoneNumbers;
				
				phoneNumbers = new long long [++phoneNumberCt];

				if(temp.phoneNumbers != nullptr){
					for(int i = 0; i < temp.phoneNumberCt ; i++){
						phoneNumbers[i] = temp.phoneNumbers[i];
					}
				}
				
				phoneNumbers[phoneNumberCt-1] = number;

			}
			return *this;
		}

	//Checks if contact name is empty
		bool Contact::isEmpty() const{return contactName[0] == '\0';}

	//Displays Contact name and numbers
		void Contact::display() const{
			if(!isEmpty()){

				string phoneNumberStr;

				cout << contactName << endl;

				for(int i = 0; i < phoneNumberCt ; i++){
					phoneNumberStr = to_string(phoneNumbers[i]);
					if(phoneNumberStr.length()==11){
						cout << "(+" << phoneNumberStr.substr(0,1)<< ") " 
						<< phoneNumberStr.substr(1,3) << " " 
						<< phoneNumberStr.substr(4,3) << "-"
						<< phoneNumberStr.substr(7,4) << endl;
					}else{
						cout << "(+" << phoneNumberStr.substr(0,2)<< ") " 
						<< phoneNumberStr.substr(2,3) << " " 
						<< phoneNumberStr.substr(5,3) << "-"
						<< phoneNumberStr.substr(8,4) << endl;
					}

				}
			}else{
				cout << "Empty contact!" << endl;
			}

		}

	//Checks whether given phone number is valid
		bool Contact::isValid(const long long phoneNumber){
			string phoneNumberStr = to_string(phoneNumber);
			return !(phoneNumber <= 0 || phoneNumberStr.length() < 11 || phoneNumberStr.length() > 12 || phoneNumberStr[2] == '0' || phoneNumberStr[5]== '0');		
		}

}