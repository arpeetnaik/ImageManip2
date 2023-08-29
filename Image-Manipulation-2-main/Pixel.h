// Arpeet Naik
// Lab 10
// CPSC 1021
// Pixel Class header file

#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>

using namespace std;

class Pixel{

	private:

		unsigned char R;
		unsigned char G;
		unsigned char B;

	public:

		Pixel(); // default constructor

		Pixel(const Pixel&); // copy constructor that takes in Pixel variable

		Pixel(unsigned char r, unsigned char g, unsigned char b); // parametrized constructor that takes in rgb values

		~Pixel(); // destructor

		unsigned char r()const; // r value getter
		unsigned char& r(); // r value reference getter

		unsigned char g()const; // g value getter
		unsigned char& g(); // g value reference getter

		unsigned char b()const; // b value getter
		unsigned char& b(); // b value reference getter

		Pixel& operator = (const Pixel&); // assignment operator overload function
		friend ostream &operator << (ostream&, const Pixel&); // output stream overload function
};



#endif
