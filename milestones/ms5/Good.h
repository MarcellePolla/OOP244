/***********************************************************
// OOP244 Aid Management Application : Milestone 5
// File Good.h
// Date Aug 3rd
// Author Marcelle Polla
// Description
// This is the header file for the Good module.
// It contains the prototypes for the Good class.
***********************************************************/
#ifndef AID_GOOD_H__
#define AID_GOOD_H__
#include <iostream>
#include "Error.h"
#include "iGood.h"

namespace aid{
	const int max_sku_length = 7; //max chars in a SKU
	const int max_unit_length = 10; //max chars in units descriptor for a Good
	const int max_name_length = 75; //max chars in user name for a Good
	const double tax_rate = 0.13;

	class Good : public iGood {
		char m_type; //type of good to use in file record
		char m_sku[max_sku_length+1];
		char m_unit[max_unit_length+1];
		char* m_name; //dynamic allocated
		int m_qnt;
		int m_qntNeed;
		double m_price;
		bool m_taxableStatus;
	protected:
		void name(const char*); //dynamically allocated good name SET
		const char* name() const; //get name
		const char* sku() const; //get SKU
		const char* unit() const; //get unit
		bool taxed() const; //taxable status
		double itemPrice() const; //get price without tax
		double itemCost() const; //get price+tax
		bool isClear() const; //for error
		void message(const char*);
		Error m_error;
	public:
		Good(const char type = 'N');
		Good(const char* sku, const char* name, const char* unit, const int qnt = 0, bool tax = true, double price = 0.0, int qntNeeded = 0 );
		Good(const Good& good);
		Good& operator=(const Good& good); 
		~Good();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);

		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		bool operator==(const char*) const; //compares sku
		double total_cost() const; //returns total cost of all goods on hand with tax
		void quantity(int); //quantity setter
		bool isEmpty() const; //checks whether good obj is in empty state
		int qtyNeeded() const; //qntNeeded getter
		int quantity() const; //qnt getter
		bool operator>(const char*) const; //compares sku 
		bool operator>(const iGood&) const; //compares good names
		int operator+=(int); //updates qnt
	};

	std::ostream& operator<<(std::ostream& os, const iGood& good);
	std::istream& operator>>(std::istream& is, iGood& good);
	double operator+=(double& cost, const iGood& good);
}
#endif