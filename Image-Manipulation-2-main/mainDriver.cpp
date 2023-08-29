// Arpeet Naik
// CPSC 1020 - Fall 2021
// PA2

#include <iostream>
#include <string>
#include "Pixel.h"
#include "Header.h"
#include "Image.h"
#include "manip.h"

using namespace std;

int printMenu();
int whichImage();

int main(int argc, char* argv[]){
  int Restart = 0;
  int imageCount = 1;


if(argc != 3){
  cerr << "USAGE: ./out <inF1.ppm> <inF2.ppm>" << endl;
  return 1;
}

  ifstream inF1(argv[1]);
  ifstream inF2(argv[2]);

  if(!inF1 || !inF2){
    cerr << "ERROR: File(s) could not be opened." << endl;
    return 1;
  }

  Image ClemsonPaw(inF1);
  Image Disney(inF2);

  Restart = printMenu();

  while(Restart){
    string count = to_string(imageCount);
    string outImage = "out_"+count+".ppm";

    ofstream out(outImage);

    if(Restart == 1){
      int imageChoice = whichImage();
      if (imageChoice == 1){
        Image gray_outClemsonPaw = ClemsonPaw;
        gray(gray_outClemsonPaw);
        gray_outClemsonPaw.write_to(out);
      }
      else{
        Image gray_outDisney = Disney;
        gray(gray_outDisney);
        gray_outDisney.write_to(out);
      }
      imageCount++;
    }
    else if(Restart == 2){
      int imageChoice = whichImage();
      if(imageChoice == 1){
        Image mirror_outClemsonPaw = ClemsonPaw;
        mirror(mirror_outClemsonPaw);
        mirror_outClemsonPaw.write_to(out);
      }
      else{
        Image mirror_outDisney = Disney;
        mirror(mirror_outDisney);
        mirror_outDisney.write_to(out);
      }
      imageCount++;
    }
    else if(Restart == 3){
      Image green_screenDisney = Disney;
      cerr << "The Clemson Paw will be copied " << endl;
      cerr << "on top of the Disney image. " << endl << endl;
      green_screen(green_screenDisney, ClemsonPaw);
      green_screenDisney.write_to(out);
      imageCount++;
    }

    out.close();
    Restart = printMenu();
  }

  inF1.close();
  inF2.close();

  return 0;
}
int printMenu() {
	int choice = 0;
	cout << "\nPA1 Image Manipulation\n";
	cout << "0. exit program \n";
	cout << "1. gray scale\n";
	cout << "2. mirror\n";
	cout << "3. green screen\n";
	cout << "   - - > ";
	cin >> choice;
	return choice;
}


int whichImage() {
	int choice = 0;
	while (choice != 1 && choice != 2) {
		cout << "\nPA1 Image Manipulation\n";
		cout << "1. ClemsonPaw.ppm\n";
		cout << "2. Disney.ppm\n";
		cout << "   - - > ";
		cin >> choice;
	}
	return choice;
}
