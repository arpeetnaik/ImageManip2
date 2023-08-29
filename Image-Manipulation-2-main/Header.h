// Arpeet Naik
// CPSC 1020 - Fall 2021
// PA2

#ifndef HEADER_H
#define HEADER_H


#include <ostream>
#include <string>
using namespace std;

class Header{
  private:

    string TYPE;
    int W, H, MAX;

  public:

    Header(); //default
    Header(const Header&); //copy
    Header(string type, int w, int h, int max); //parametrized

    ~Header(); // destructor

    string getType() const;
    int getW() const;
    int getH() const;
    int getMax() const;

    Header& operator = (const Header&);
    friend ostream& operator << (ostream&, const Header&);

};

#endif
