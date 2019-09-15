/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	graph.h
// Version 1.0
// Date	2019/05/11
// Author	Marcelle Polla
// Section B
// Student Number 126654185
// email mpolla1@myseneca.ca
// Description
// This is the header file for graph
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H

namespace sict{

//Definitions//

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

//Prototypes//

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);

// Finds the largest sample in the samples array if it is larger than 70,
// otherwise it will return 70. 
int findMax(int samples[], int noOfSamples);

// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);

// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);

}

#endif