/***********************************************************
// OOP244 Aid Management Application : Milestone 5
// File Error.cpp
// Date Aug 3rd
// Description
// This is the implementation file for the Error module.
// It contains the methods for the Error class.
***********************************************************/
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;
namespace aid{
//constructor
	Error::Error(const char *msg):m_errorMessage(nullptr){
		if(msg == nullptr || msg[0] == '\0')
			clear();
		else
			message(msg);
	}
//destructor
	Error::~Error(){
		clear();
	}
//sets obj to empty state
	void Error::clear(){
		delete [] m_errorMessage;
		m_errorMessage = nullptr;
	}
//checks if obj is in empty state
	bool Error::isClear() const{
		return m_errorMessage == nullptr;
	}
//sets message
	void Error::message(const char *str){
		clear();
		if(str[0] != '\0'){
			m_errorMessage = new char[strlen(str) + 1];
			strcpy(m_errorMessage, str);
		}
	}
//queries message
	const char* Error::message() const{
		return m_errorMessage;
	}
//operator overload
	std::ostream& operator<<(std::ostream& os, const Error& err){
		if(!err.isClear())
			os << err.message();
		return os;
	}
}
