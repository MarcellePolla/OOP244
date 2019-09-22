/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
// Version 3.0
// 2019/05/30
// MarcellePolla
// Description
// This workshop demonstrates classes in C++ and 
// how member variables are defined privately, but 
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
//         
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include "CRA_Account.h"
#include "CRA_Account.h" // intentional

using namespace std;
using namespace sict;

int main() {
	const int size = 1000;
	char familyName[size];
	char givenName[size];
	sict::CRA_Account myCRA;
	int sin;
	bool quit = false;
	if (sict::max_name_length + 1 > size) {
		cerr << "Increase size to value greater than " 
			<< sict::max_name_length + 1 << endl;
		return 1;
	}

	cout << "Canada Revenue Agency Account App" << endl
		 << "=================================" << endl << endl;
	cout << "Checking constants" << endl
		<< "---------------------------------" << endl
		<< "max_name_length: " << sict::max_name_length << endl
		<< "        min_sin: " << sict::min_sin << endl
		<< "        max_sin: " << sict::max_sin << endl
		<< "---------------------------------" << endl << endl;
	cout << "Please enter your family name: ";
	cin >> familyName;
	cin.ignore();
	cout << "Please enter your given name: ";
	cin >> givenName;
	cin.ignore();

	do {
		cout << "Please enter your social insurance number (0 to quit): ";
		cin >> sin;
		cin.ignore();
		if (sin != 0)
		{
			myCRA.set(familyName, givenName, sin);
			if (myCRA.isEmpty()) {
				cout << "Invalid input! Try again." << endl;
			}
			else {
				quit = true;
			}
		}
		else {
			quit = true;
		}
	} while (!quit);
	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	myCRA.display();
	cout << "----------------------------------------" << endl;
	
	return 0;
}