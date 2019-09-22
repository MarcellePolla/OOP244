/***********************************************************
// OOP244 Workshop 5: Member Operator Overloads
// File Fraction.h
// Version 1.0
// Date June 15th
// Description
// This is the header file for the Fraction module.
// It contains the prototypes for the Fraction class.
// 
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Header safeguards
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// sict namespace
namespace sict{
	//Fraction class
	class Fraction {
//instance variables 
		int numerator;
		int denominator;

//private member functions
//returns the greater of the numerator and denominator
		int max() const;
//returns the lesser of the numerator and denominator
		int min() const;
//reduces the numerator and denominator 
		void reduce();
//returns the greatest common divisor of the numerator and denominator
		int gcd() const;
	public:
		//constructors
		Fraction();
		Fraction(int n, int d);
//returns true if the object is in a safe empty state
		bool isEmpty() const;
//inserts the fraction into standard output
		void display() const;
		//operator overload
		Fraction operator+(const Fraction& rhs) const;

	};
}
#endif
	
