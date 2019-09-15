/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	seneGraph.cpp
// Version 1.0
// Date	2019/05/11
// Author	Marcelle Polla
// Section B
// Student Number 126654185
// email mpolla1@myseneca.ca
// Description
// This is the main for seneGraph 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "graph.h"
#include "tools.h"
using namespace sict;
using namespace std;

int main(){
	int noOfSamples = 0;
  int samples[MAX_NO_OF_SAMPLES] = { 0 };
  bool done = false;
  cout << "Welcome to SeneGraph" << endl;
  while (!done){
    cout << "No Of Samples: " << noOfSamples << endl;
    switch (menu()){
    case 1:
      cout << "Enter number of samples on hand: ";
      noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
      break;
    case 2:
      if (noOfSamples == 0){
        cout << "First enter the number of Samples." << endl;
      }
      else{
        cout << "Please enter the sample values: " << endl;
        getSamples(samples, noOfSamples);
      }
      break;
    case 3:
      if (noOfSamples == 0){
        cout << "First enter the number of Samples." << endl;
      }
      else if (samples[0] == 0){
        cout << "Firt enter the samples." << endl;
      }
      else{
        printGraph(samples, noOfSamples);
      }
      break;
    case 0:
      cout << "Thanks for using SeneGraph" << endl;
      done = true;
    }
  }

	return 0;
}