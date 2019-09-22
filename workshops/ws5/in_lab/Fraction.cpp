/***********************************************************
// OOP244 Workshop 5: Member Operator Overloads
// File Fraction.cpp
// Version 1.0
// Date June 15th
// Author Marcelle Polla
// Description
// This is the implementation file for the Fraction module.
// It contains the function definitions for the Fraction class.
// 
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Headers
#include <iostream>
#include "Fraction.h"
using namespace std;

//the sict namespace
namespace sict{
 //default constructor
    Fraction::Fraction(){
        numerator = 0;
        denominator = 0;
    }
//two-argument constructor
    Fraction::Fraction(int n, int d){
        if(n>0 && d>0){
                numerator = n;
                denominator = d;
                reduce();
            }
            else
            {
                numerator = 0;
                denominator = 0;
            }
    }

//returns the greater of numerator and denominator
        int Fraction::max() const{
            if(numerator>denominator)
                return numerator;
            else
                return denominator;
        }
//returns the lesser of numerator and denominator
        int Fraction::min() const{
            if (numerator < denominator)
                return numerator;
            else
                return denominator;
        }
    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

//reduces the numerator and denominator 
        void Fraction::reduce(){
            int gcd = this->gcd();
            numerator = numerator/ gcd;
            denominator = denominator/gcd; 
        }

//inserts the fraction into standard output
        void Fraction::display() const{
            if(denominator > 1 && numerator > 0){
                cout << numerator << "/" << denominator;
            }
            else if(denominator == 1 && numerator > 0){
                cout << numerator;
            }
            else if(this->isEmpty()){
                cout << "no fraction stored";
            }
        }
//returns true if the object is in a safe empty state
        bool Fraction::isEmpty() const{
            if(this->numerator == 0 && denominator == 0){
                return true;
            }
            else
                return false;
        }

//operator overload
        Fraction Fraction::operator+(const Fraction& rhs) const{
            if(this->isEmpty() == false && rhs.isEmpty() == false){
                int d = this->denominator * rhs.denominator;
                int n = ((d/this->denominator)*this->numerator) + ((d/rhs.denominator)*rhs.numerator);
                Fraction nFraction = Fraction(n, d);
                nFraction.reduce();
                return nFraction;      
            }else{
                Fraction nFraction = Fraction();
                return nFraction;
            }                  
        }
}

	