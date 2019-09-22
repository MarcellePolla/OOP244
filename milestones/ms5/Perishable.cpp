/***********************************************************
// OOP244 Aid Management Application : Milestone 5
// File Perishable.cpp
// Date Aug 3rd
// Author Marcelle Polla
// Description
// This is the implementation file for the Perishable module.
// It contains the methods for the Perishable class.
***********************************************************/
#include <iostream>
#include <fstream>
#include "Perishable.h"
using namespace std;

namespace aid{
	Perishable::Perishable() : Good('P'){}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const{
		Good::store(file, false);
		file << ",";
		expiry().write(file);
		if(newLine)
			file << '\n';
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file){
		Good::load(file);
		m_expiryDateObj.read(file);
		file.ignore();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const{
		Good::write(os, linear);

		if(isClear() && !isEmpty()){ 
			if(linear){
				expiry().write(os);
			}
			else{
				os << "\n Expiry date: ";
				expiry().write(os);
			}		
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is){
		Good::read(is);
		if(!is.fail()){
			Date tempDate;
			cout << " Expiry date (YYYY/MM/DD): ";
			tempDate.read(is);

			if(tempDate.bad()){
				is.setstate(std::ios::failbit);
				if(tempDate.errCode() == 1)
					message("Invalid Date Entry");
				else if(tempDate.errCode() == 4)
					message("Invalid Year in Date Entry");
				else if(tempDate.errCode() == 3)
					message("Invalid Month in Date Entry");
				else if(tempDate.errCode() == 2)
					message("Invalid Day in Date Entry");
				else if(tempDate.errCode() == 5)
					message("Invalid Expiry in Date Entry");
			}else{
				m_expiryDateObj = tempDate;	
				m_error.clear();	
			}
		}
		return is;
	}

	const Date& Perishable::expiry() const{ return m_expiryDateObj; }

	iGood* CreateProduct(char tag){
		iGood* product = nullptr;
		if(tag == 'n' || tag == 'N')
			product = new Good();
		if(tag == 'p' || tag =='P')
			product = new Perishable();
		return product;
	}
}