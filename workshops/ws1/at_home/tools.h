/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	tools.h
// Version 1.0
// Date	2019/05/11
// Author	Marcelle Polla
// Section B
// Student Number 126654185
// email mpolla1@myseneca.ca
// Description
// This is the header file for tools
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SICT_TOOLS_H
#define SICT_TOOLS_H

namespace sict{

//Prototypes//

// Performs a fool-proof integer entry
int getInt(int min, int max);

// Displays the user interface menu
int menu();

}


#endif