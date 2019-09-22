// Final Project Milestone 4 - Product Interface
// Version 3.7
// ms4_MyGood.h
// 2018/06/22
// Authors	Fardad Soleimanloo, Chris Szalwinski, cornel
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AID_MYPRODUCT_H__
#define AID_MYPRODUCT_H__
#include "iGood.h"
#include "iGood.h"
#include "iGood.h" // Good.h is included three times on purpose.

namespace aid {
  class MyGood : public iGood {
    char text_[10000];
	char sku[4];
	char name_[20];
	int value;
  public:
    MyGood(const char* name);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
	bool operator==(const char*) const;
	double total_cost() const;
	const char* name() const;
	void quantity(int);
	int qtyNeeded() const;
	int quantity() const;
	int operator+=(int);
	bool operator>(const iGood&) const;
  };
}
#endif