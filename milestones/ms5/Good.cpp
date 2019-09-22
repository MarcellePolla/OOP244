/***********************************************************
// OOP244 Aid Management Application : Milestone 5
// File Good.cpp
// Date Aug 3rd
// Description
// This is the implementation file for the Good module.
// It contains the methods for the Good class.
***********************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Good.h"
using namespace std;
namespace aid{

//set dynamically allocated good name
	void Good::name(const char* name){
		delete[] m_name;
		if (name) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}else{
			delete[] m_name;
			m_name = nullptr;
		}
	} 
//get name
	const char* Good::name() const{ return m_name == nullptr ? " " : m_name;}
//get sku
	const char* Good::sku() const{ return m_sku;}
//get unit
	const char* Good::unit() const{ return m_unit;}
//get taxable status
	bool Good::taxed() const{return m_taxableStatus;}
//get price without tax
	double Good::itemPrice() const{return m_price;}
//get total cost with tax
	double Good::itemCost() const{ return (taxed() ? ((m_price * tax_rate) + m_price) : m_price);}
//set error
	void Good::message(const char* msg){ m_error.message(msg);}
//get error status
	bool Good::isClear() const{ return m_error.isClear();}

//constructors
	Good::Good(const char type){
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_qnt = 0;
		m_qntNeed = 0;
		m_price = 0.0;
		m_taxableStatus = false;
	}	

	Good::Good(const char* sku, const char* nm, const char* unit, int qnt, bool tax, double priceBeforeTax, int qntNeeded){
		strncpy(m_sku, sku, max_sku_length);
		m_sku[max_sku_length] = '\0';
		strncpy(m_unit, unit, max_unit_length);
		m_unit[max_unit_length] = '\0';
		name(nm);
		quantity(qnt);
		m_qntNeed = qntNeeded;
		m_price = priceBeforeTax;
		m_taxableStatus = tax;
	}

	Good::Good(const Good& good){
		m_name=nullptr;
		*this = good;
	}

//copy assignment
	Good& Good::operator=(const Good& good){
		if(this != &good){
			m_type = good.m_type;
			strcpy(m_sku, good.sku());
			strcpy(m_unit, good.unit());
			name(good.m_name);
			m_qnt = good.quantity();
			m_qntNeed = good.qtyNeeded();
			m_price = good.itemPrice();
			m_taxableStatus = good.taxed();
		}	
		return *this;
	}
//destructor
	Good::~Good(){
		delete [] m_name;
	}
//fstream methods
	std::fstream& Good::store(std::fstream& file, bool newLine) const{
		if(file.is_open()){
			file << m_type<< "," << m_sku << "," << m_name << "," << m_unit << "," << m_taxableStatus << ","  << m_price << ","  << m_qnt  << "," << m_qntNeed; 
			if(newLine) file << std::endl;
		}
		return file;
	}
	std::fstream& Good::load(std::fstream& file){
		Good g;

		g.m_name = new char[max_name_length + 1];

		file.getline(g.m_sku, max_sku_length, ',');
		file.getline(g.m_name, max_name_length, ',');
		file.getline(g.m_unit, max_unit_length, ',');
		file >> g.m_taxableStatus;
		file.ignore();
		file >> g.m_price; 
		file.ignore();
		file >> g.m_qnt;
		file.ignore();
		file >> g.m_qntNeed;
		file.ignore();

		*this = g;

		return file;
	}

//ostream methods
	std::ostream& Good::write(std::ostream& os, bool linear) const{
		
		if(!isClear()) os << m_error.message();
		
		else if(!isEmpty()){
			if(linear){
			os << setfill(' ') << left
			<<setw(max_sku_length)  << sku() << "|" 
			<< setw(20)<< left << name() << "|" 
			<< right 
			<< fixed << setw(7) << setprecision(2) << itemCost() << "|" 
			<< setw(4) << quantity() << "|" 
			<< left << setw(10) << unit() << "|" 				
			<< fixed << right << setw(4) << qtyNeeded() << "|"; 
		}else{
			os << " Sku: " << sku() << endl;  
			if(strlen(name()) > 74)
				os << " Name (no spaces): " << setprecision(74) << name() << endl;
			else
				os << " Name (no spaces): " << name() << endl;
			os << " Price: " << itemPrice()<< endl;
			if(taxed())
				os << " Price after tax: " << itemCost() << endl;
			else
				os << " Price after tax: N/A" << endl;
			os << " Quantity on hand: " << quantity() << " " << unit() << endl
			<< " Quantity needed: " << qtyNeeded();
			}
		}
		
		return os;
	}

	std::istream& Good::read(std::istream& is){
		char n[max_name_length+1];
		char tax;

		cout << " Sku: ";
		is >> m_sku;
		
		cout << " Name (no spaces): ";
		is >> n;
		name(n);

		cout << " Unit: ";
		is >> m_unit;
			
		cout << " Taxed? (y/n): ";
		is >> tax;

		if(tax == 'y' || tax == 'Y')	m_taxableStatus = true;
		else if(tax == 'n' || tax == 'N') m_taxableStatus = false;
		else{
			message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}
		
		if(!is.fail()){
			cout << " Price: ";
			is >> m_price;
			if(is.fail()){
				message("Invalid Price Entry");
				is.setstate(std::ios::failbit);
			}
		}
					
		if(!is.fail()){
			cout << " Quantity on Hand: ";
			is >> m_qnt;
			if(is.fail()){
				message("Invalid Quantity Entry");
				is.setstate(std::ios::failbit);
			}
		}			
		
		if(!is.fail()){
			cout << " Quantity needed: ";
			is >> m_qntNeed;
			is.ignore();
			if(is.fail()){
				message("Invalid Quantity Needed Entry");
				is.setstate(std::ios::failbit);
			}
		}

		if(!is.fail()){
			m_error.clear();
		}
		return is;
	}

//compares sku
	bool Good::operator==(const char* sku) const{ return strcmp(m_sku, sku)==0;}
//cost of all items with tax
	double Good::total_cost() const{return itemCost() * m_qnt;}
//quantity setter
	void Good::quantity(int q){m_qnt = q;}
//checks for empty state
	bool Good::isEmpty() const{return m_name == nullptr;}
//qnt needed getter
	int Good::qtyNeeded() const{return m_qntNeed;}
//qnt getter
	int Good::quantity() const{return m_qnt;}
//compares sku
	bool Good::operator>(const char* s) const{ return strcmp(m_sku, s) == 1;}
//compares good names
	bool Good::operator>(const iGood& good) const{ return strcmp(m_name, good.name()) > 0;}
//updates qnt
	int Good::operator+=(int i){return ((i>0)? m_qnt+= i : m_qnt);}

//helper functions
	std::ostream& operator<<(std::ostream& os, const iGood& good){
		good.write(os, true); 
		return os;
	}

	std::istream& operator>>(std::istream& is, iGood& good){
		good.read(is);
		return is;
	}

	double operator+=(double& cost, const iGood& good){
		return good.total_cost() + cost;
	}
}
