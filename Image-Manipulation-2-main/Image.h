// Arpeet Naik
// CPSC 1020 Fall 2021
// PA2
// Image Header File
#ifndef IMAGE_H
#define IMAGE_H

#include <ostream>
#include <vector>
#include <fstream>
#include "Pixel.h"
#include "Header.h"

using namespace std;

class Image{
  private:

    Header header;
    vector<Pixel> pixels;

    vector<Pixel> read_pixels(const Header& header, ifstream& input);
    Header read_header(ifstream& input);

    Image& operator=(const Image& image);

  public:

    //copy constructors
    Image(const Image& input);
    Image(ifstream& image);
    
    //destructor
    ~Image();

    //parameterized constructor
    Pixel& operator()(int x, int y);

    void write_header(ofstream& output) const;
    void write_to(ofstream& output) const;

    const Header getHeader() const;
    const vector<Pixel> getPixels() const;

};

#endif
