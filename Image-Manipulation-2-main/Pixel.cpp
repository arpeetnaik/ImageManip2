// Arpeet Naik
// Lab 10
// CPSC 1021
// Implementation file for Pixel class

#include "Pixel.h"


// default constructor
Pixel::Pixel(){
	R = 0.0;
	G = 0.0;
	B = 0.0;
}
// copy constructor
Pixel::Pixel(const Pixel &obj){
	R = obj.R;
	G = obj.G;
	B = obj.B;
}
// parametrized constructor
Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b){
	this -> R = r;
	this -> G = g;
	this -> B = b;
}

// destructor
Pixel::~Pixel(){
}

unsigned char Pixel::r()const{
	return this -> R;
}

unsigned char Pixel::g()const{
	return this -> G;
}

unsigned char Pixel::b()const{
	return this -> B;
}

unsigned char &Pixel::r(){
	return this -> R;
}

unsigned char &Pixel::g(){
	return this -> G;
}

unsigned char &Pixel::b(){
	return this -> B;
}

Pixel &Pixel::operator = (const Pixel &obj){
	if(this != &obj){

	this -> R = obj.R;
	this -> G = obj.G;
	this -> B = obj.B;

	}

	return *this;
}

ostream &operator << (ostream &output, const Pixel &obj){
	return output << "(" << obj.R << " " << obj.G << " " << obj.B << ")";

}
