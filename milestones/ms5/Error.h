/***********************************************************
// OOP244 Aid Management Application : Milestone 5
// File Error.h
// Date Aug 3rd
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
		virtual ~Error();
		Error(const Error&) = delete;
		Error operator=(const Error&) = delete;

		void clear();
		bool isClear() const;
		void message(const char *str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& err);
}
#endif
