/***********************************************************
// OOP244 Workshop 6: Class with a resource
// File Contact.h
// Version 1.0
// Date July 13th
// Author Marcelle Polla
// Description
// This is the header file for the Contact module.
// It contains the prototypes for the Contact class.
// 
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Header safeguards
#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__

// sict namespace
namespace sict{
	const int MAX_CHAR = 20;

	class Contact{
		char contactName[MAX_CHAR+1];
		long long * phoneNumbers;
		int phoneNumberCt;
		bool isValid(const long long phoneNumber);

	public:
		Contact();
		Contact(const char * name, const long long * numbers, int ct);
		Contact(const Contact &contact);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator=(const Contact &contact); 
		Contact& operator+=(const long long number);
	};
}

#endif