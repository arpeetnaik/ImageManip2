// Arpeet Naik
// CPSC 1020 - Fall 2021
// PA2

#include "Header.h"

Header::Header(){
  TYPE = "";
  W = 0;
  H = 0;
  MAX = 0;
}

Header::Header(const Header &obj){
  this->TYPE = obj.TYPE;
  this->W = obj.W;
  this->H = obj.H;
  this->MAX = obj.MAX;
}

Header::Header(string type, int w, int h, int max){
  this->TYPE = type;
  this->W = w;
  this->H = h;
  this->MAX = max;
}

Header::~Header(){

}

string Header::getType() const {
  return this->TYPE;
}

int Header::getW() const{
  return this->W;
}

int Header::getH() const{
  return this->H;
}

int Header::getMax() const{
  return this->MAX;
}

Header& Header::operator=(const Header &obj){
  if(this != &obj){
    this->TYPE = obj.TYPE;
    this->W = obj.W;
    this->H = obj.H;
    this->MAX = obj.MAX;
  }
  return *this;
}
