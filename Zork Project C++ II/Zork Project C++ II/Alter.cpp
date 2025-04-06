#include <iostream>
#include "Alter.h"

using std::cout;
using std::endl;

Alter::Alter() {
    paperPlaced = false;
}

void Alter::placePaper() {
    cout << "\nYou set the scroll gently onto the alter. Just as it's placed, the scroll evaporates into vaporous flames." << endl
        << "And just at that moment, you hear a monstrous roar coming from somewhere far off to the south." << endl
        << "Your mind only takes one moment to recognize the roar... It was the same one you heard when you had first awoken in this place...\n" << endl;
    paperPlaced = true;
}
