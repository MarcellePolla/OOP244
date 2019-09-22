/***********************************************************
// OOP244 Aid Management Application : Milestone 4
// File iGood.h
// Date July 28th
// Author Marcelle Polla
// Description
// This is the header file for the iAccount class.
// It contains the prototypes for the iAccount class.
***********************************************************/
#ifndef AID_IGOOD_H__
#define AID_IGOOD_H__
#include <iostream>
#include <fstream>
namespace aid{

	class iGood{
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine=true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iGood&) const = 0;
		virtual ~iGood() {};
	};

	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);
	iGood* CreateProduct(char tag);
}

#endif