// Arpeet Naik
// CPSC 1021 - Fall 2021
// PA2

#include "Image.h"

//copy constructor
Image::Image(const Image& input){
  this->header = input.header;
  this->pixels = input.pixels;

}

//copy constructor
Image::Image(ifstream& image){
  header = read_header(image);
  pixels = read_pixels(header, image);

}

//destructor
Image::~Image(){}

vector<Pixel> Image::read_pixels(const Header& header, ifstream& input){

  int numpixels = header.getW()*header.getH();
  vector<Pixel> pixels(numpixels);
  unsigned char r,g,b;
  for(Pixel& p:pixels){

    r = input.get();
    g = input.get();
    b = input.get();
    p = Pixel(r,g,b);

  }
  return pixels;
}

Header Image::read_header(ifstream& input){

  string type;
  int w, h, max;

  input >> type;
  input >> w >> h >> max;
  input.ignore(256,'\n');

  Header header(type, w, h, max);

  return header;
}

Pixel& Image::operator()(int x, int y){
  x = x*header.getW() + y;
  return pixels[x];
}

void Image::write_header(ofstream& output) const{
  output << header.getType() << " ";
  output << header.getW() << " " << header.getH() << " ";
  output << header.getMax() << "\n";
}

void Image::write_to(ofstream & output) const{
  write_header(output);
  for(const Pixel x:pixels){
    output << x.r() << x.g() << x.b();
  }
}

const Header Image::getHeader() const{
  return this->header;
}

const vector<Pixel> Image::getPixels() const{
  return this->pixels;
}
