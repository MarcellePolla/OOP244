
/***********************************************************
// OOP244 Workshop 9: Function Templates
// File Data.cpp
// Date Aug 1st
// Description
// This is the implementation file for the Data module.
// It contains the methods for the Data class.
***********************************************************/
#include <iostream>
#include "Data.h"
using namespace std;
namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double populationChange = static_cast<double>(population[n-1] - population[0])/1000000;
		cout << "Population change from "<< year[0]<<" to " << year[n-1]<< " is "<< fixed << setprecision(2) << populationChange << " million" <<endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		if(violentCrimeRate[0] > violentCrimeRate[n-1])
			cout << "Violent Crime trend is down" << endl;
		else
			cout << "Violent Crime trend is up" << endl;

		// Q3 print the GTA average
		cout << "There are " << setprecision(2) << average(grandTheftAuto,n)/1000000 << " Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates

		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

	}
}
