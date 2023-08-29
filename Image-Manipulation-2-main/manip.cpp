// Arpeet Naik
// CPSC 1020 - Fall 2021
// PA2

#include "manip.h"

void gray(Image& image){

  unsigned char average = 0;

  for(int rows = 0; rows < image.getHeader().getH(); rows++){
    for(int cols = 0; cols < image.getHeader().getW(); cols++){

      Pixel& imagePixel = image(rows, cols);
      average = (imagePixel.r() + imagePixel.g() + imagePixel.b()) / 3;

      Pixel grayPixel(average, average, average);
      image(rows, cols) = grayPixel;
    }
  }
}

void mirror(Image& image) {


	for (int rows = 0; rows < image.getHeader().getH(); rows++) {
		int tempVar = image.getHeader().getW() - 1;
		// half the distance across the image
		for (int cols = 0; cols < image.getHeader().getW()/2; cols++) {
			// swap pixels
			Pixel temp = image(rows,cols);
			image(rows,cols) = image(rows,tempVar);
			image(rows,tempVar) = temp;
			tempVar--;
		}
	}
}

void green_screen(Image& Disney, Image& ClemsonPaw){


  for(int rows = 0; rows < ClemsonPaw.getHeader().getH(); rows++){
    for(int cols = 0; cols < ClemsonPaw.getHeader().getW(); cols++){

      if( (ClemsonPaw(rows,cols).r() != 0) && (ClemsonPaw(rows,cols).g() != 255) &&
      (ClemsonPaw(rows,cols).b() != 0)){

        Disney(rows,cols).r() = ClemsonPaw(rows,cols).r();
        Disney(rows,cols).g() = ClemsonPaw(rows,cols).g();
        Disney(rows,cols).b() = ClemsonPaw(rows,cols).b();

      }
    }
  }
}
