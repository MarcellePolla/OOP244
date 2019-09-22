/***********************************************************
// OOP244 Aid Management Application : Milestone 2
// File Error.h
// Date July 15th
// Author Marcelle Polla
// Description
// This is the header file for the Error module.
// It contains the prototypes for the Error class.
***********************************************************/
#ifndef AID_ERROR_H__
#define AID_ERROR_H__
#include <iostream>
namespace aid{
	class Error{
		char* m_errorMessage;
	public:
		explicit Error(const char *msg= nullptr);
		~Error();
		void clear();
		bool isClear() const;
		void message(const char *str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& err);
}
#endif