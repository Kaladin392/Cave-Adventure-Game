#include <iostream>
#include "Portal.h"

using std::cout;
using std::endl;

Portal::Portal() {
    portalActive = false;
    enteredPortal = false;
    activated = false;
}

void Portal::ActivatePortal(const std::string& item) {
    if (!activated) {
        cout << "\nAs you reach to place the green orb into the slot, the orb lurches away from your hand into it's place, as if magnetized." << endl
            << "Before you can react, a blinding green light engulfs the room. As the light stabilizes, you glance up to notice a green portal, swirling in emerald light." << endl
            << "It seems the green orb has activated the portal, but where does it lead?\n" << endl;
        activated = true;
    }
    else if (activated)
    {
        cout << "\nThe portal once again hums to life in a swathe of emerald light.\n" << endl;
    }
    portalActive = true;
}

void Portal::RetrieveOrb() {
    cout << "\nYou walk in front of the portal and reach to take the orb back. The portal evaporates as the orb is lifted from it's divot.\n" << endl;
    portalActive = false;
}

void Portal::portalInvestigation() {
    if (!portalActive)
    {
        cout << "\nThe platform has strange runic glyphs drawn out upon it's foundation. In the center, there's a spherical divot with green runes on the inside. Perhaps something is meant to fit within?\n" << endl;
    }
    else cout << "\nThe portal is humming and buzzing with energy as the room is filled with the emerald light it gives off. It seems to beckon you into it...\n" << endl;
}