#include <iostream>
#include "Pedestal.h"

using std::cout;
using std::endl;

Pedestal::Pedestal() {
    swordPlaced = false;
}

void Pedestal::InvestigatePedestal() {
    if (!swordPlaced) {
        cout << "\nThe stone of the pedestal has a strange, almost metallic glow... Black, writhing lines trace the hard edges of the pedestal on all sides." << endl
            << "On the top of the pedestals flat head, a small, blade shaped slope enters inward." << endl
            << "It seems a sword of some kind is supposed to be placed within this stone pedestal...\n" << endl;
    }
    else {
        cout << "\nThe black sword juts out from the top of the pedestal, blade inserted inside, black steel hilt gleaming from the crystal light.\n" << endl;
    }
}

void Pedestal::PlaceSword() {
    cout << "\nYou approach the stone pedestal, ready to draw the sword and sheathe it into the stone below." << endl
        << "As you reach for the swords hilt you brace yourself for the pain that drawing the blade seems to give." << endl
        << "In one quick motion, you unsheathe the sword and slam it into the pedestals blade shaped divot. As you do, the blade once again speaks through your mind." << endl
        << "Voice in the Sword: 'Haha, yes! Thank you for returning me here, feels good to be in my spot once more. That evil scientist thought it would be fun to take me for a spin but little did he know slaying evil is my expertise!'" << endl
        << "The blade seems to stop in thought before saying 'Wait, you are not evil are you? Well, you helped me defeat the evil dragon so I think Vasher would vouch for you. Well, time to slumber and wait some more...'" << endl
        << "And as your mind silences once more and you take your hands from the blades hilt, a small hatch opens up in the center of the pedestal, revealing a stark blue orb, just like the other two you have seen." << endl
        << "Bending down, you pick up the orb and add it to your collection as you bid the sword a final fair-well." << endl;
    cout << "\nYOU HAVE OBTAINED THE BLUE ORB\n\n";
}