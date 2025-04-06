#include <iostream>
#include "FinalDoor.h"

using std::cout;
using std::endl;

FinalDoor::FinalDoor() {
    placedGreen = false;
    placedRed = false;
    placedBlue = false;
}

void FinalDoor::placeGreen() {
    cout << "\nYou place the green orb in it's proper place...\n" << endl;
    placedGreen = true;
}

void FinalDoor::placeRed() {
    cout << "\nYou place the red orb in it's proper place...\n" << endl;
    placedRed = true;
}

void FinalDoor::placeBlue() {
    cout << "\nYou place the blue orb in it's proper place...\n" << endl;
    placedBlue = true;
}

void FinalDoor::retrieveGreen() {
    cout << "\nYou take the green orb from it's place on the door.\n" << endl;
    placedGreen = false;
}

void FinalDoor::retrieveRed() {
    cout << "\nYou take the red orb from it's place on the door.\n" << endl;
    placedRed = false;
}

void FinalDoor::retrieveBlue() {
    cout << "\nYou take the blue orb from it's place on the door.\n" << endl;
    placedBlue = false;
}
