/***********************************************************
// OOP244 Aid Management Application : Milestone 3
// File Good.cpp
// Date July 20th
// Description
// This is the implementation file for the Good module.
// It contains the methods for the Good class.
***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Good.h"
#include "Error.h"
using namespace std;
namespace aid{

//set dynamically allocated good name
	void Good::name(const char* value){
		delete[] m_name;
		if (value) {
			m_name = new char[strlen(value) + 1];
			strcpy(m_name, value);
		}else{
			delete[] m_name;
			m_name = nullptr;
		}
	} 
//get name
	const char* Good::name() const{ return m_name;}
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

	Good::Good(const char* sku, const char* nm, const char* unit, int qnt, bool tax, double priceBeforeTax, int qntNeeded): m_name(nullptr){
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
			file << m_type<< "," << m_sku << "," << m_name << "," << m_unit << "," << m_qnt << "," << m_taxableStatus << "," << m_price << "," << m_qntNeed; 
			if(newLine) file << std::endl;
		}
		return file;
	}
	std::fstream& Good::load(std::fstream& file){
		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  qnt, qntNeed;
		double price;
		char taxed;

		if(file.is_open()){
			file >> sku >> name >> unit >> taxed >> price >> qnt >> qntNeed;
			Good good(sku, name, unit, qnt, taxed != 0, price, qntNeed);
			*this = good;
		}
		return file;
	}

//ostream methods
	std::ostream& Good::write(std::ostream& os, bool linear) const{
		if(linear){
				os << setw(max_sku_length)<< left  << sku() << "|" 
				<< setw(20)<< left << name() << "|" 
				<< fixed <<right << setw(7) << setprecision(2) << itemCost() << "|" 
				<< setw(4) << quantity() << "|" << setw(10) << unit() << "|" 
				<< setw(4) << qtyNeeded() << "|"; 
			}else{
				os << "Sku: " << sku() << endl;  
				if(strlen(name()) > 74){
					os << "Name (no spaces): " << setprecision(74) << name() << endl;
				}
				else
					os << "Name (no spaces): " << name() << endl;
				if(taxed()){
					os << "Price: " << itemCost() << endl;
				}
				else{
					os << "N/A" << "|" << endl;
				}
					os << "Quantity on hand: " << quantity() << "|" << endl
					<< "Quantity needed: " << qtyNeeded() << "|" << endl;
			}
		return os;
	}

	std::istream& Good::read(std::istream& is){
		char sku[max_sku_length+1];
		char name[max_name_length+1];
		char unit[max_unit_length+1];
		int qnt;
		char tax;
		bool taxStatus;
		double price;
		int qntNeed;
		Error error;

		cout << "Sku: ";
		is >> sku;
		
		cout << "Name (no spaces): ";
		is >> name;

		cout << "Unit: ";
		is >> unit;
			
		cout << "Taxed? (y/n): ";
		is >> tax;

		if(tax == 'y' || tax == 'Y')	taxStatus = true;
		else if(tax == 'n' || tax == 'N') taxStatus = false;
		else{
			is.setstate(std::ios::failbit);
			error.message("Only (Y)es or (N)o are acceptable");
		}
		
		if(!is.fail()){
			cout << "Price: ";
			is >> price;
			if(is.fail())
				error.message("Invalid Price Entry");
		}
					
		if(!is.fail()){
			cout << "Quantity on hand: ";
			is >> qnt;
			if(is.fail())
				error.message("Invalid Quantity Entry");
		}			
		
		if(!is.fail()){
			cout << "Quantity needed: ";
			is >> qntNeed;
			if(is.fail()){
				error.message("Invalid Quantity Needed Entry");
			}
		}

		if(!is.fail()){
			Good temp(sku, name, unit, qnt, taxStatus, price, qntNeed);
			if(!temp.isEmpty())
			*this = temp;
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
	bool Good::isEmpty() const{return m_name[0] == '\0' && m_sku[0] == '\0' && m_unit[0] == '\0';}
//qnt needed getter
	int Good::qtyNeeded() const{return m_qntNeed;}
//qnt getter
	int Good::quantity() const{return m_qnt;}
//compares sku
	bool Good::operator>(const char* s) const{ return strcmp(m_sku, s) == 1;}
//compares good names
	bool Good::operator>(const Good& good) const{ return m_name > good.m_name;}
//updates qnt
	int Good::operator+=(int i){return ((i>0)? m_qnt+= i : m_qnt);}

//helper functions
	std::ostream& operator<<(std::ostream& os, const Good& good){
		good.write(os, true); // check this true thing later <===============================
		return os;
	}

	std::istream& operator>>(std::istream& is, Good& good){
		good.read(is);
		return is;
	}

	double operator+=(double& cost, const Good& good){
		return good.total_cost() + cost;
	}
}
