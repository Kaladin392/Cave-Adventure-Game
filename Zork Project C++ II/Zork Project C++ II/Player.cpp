#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

Player::Player() {
    p_Location = MapStart;
}

void Player::Commands(const string& command) {
    string check2 = command.substr(0, 2); //checks if command is go
    string check3 = command.substr(0, 3); //checks if command is use (eventually implement a way to use items [keys, weapons, orbs, etc.])
    string check4 = command.substr(0, 4); //checks if command is take, drop, talk or give
    string check5 = command.substr(0, 5); //checks if command is enter, place or close
    string check7 = command.substr(0, 7); //checks if command is sheathe
    string check8 = command.substr(0, 8); //checks if command is retrieve
    string check11 = command.substr(0, 11); //checks if command is investigate

    if (command == "commands" || command == "show commands")
    {
        cout << "\nCOMMANDS:\n*[go (main cardinal direction)]: move throughout the map\n*[look]: shows area description\n*[inventory]: displays player inventory\n*[commands]: displays command list\n*[take (item)]: add area item into player inventory\n*[drop (item)]: drop item from player inventory into the room\n*[talk to (object)]: attempt to talk to something\n*[give to (object) -> (item)]: attempt to give an item to something\n*[enter (object)]: attempt to enter something\n*[place -> (object) -> (item)]: attempt to place an item onto an object\n" << endl;
    }

    if (command == "look")
    {
        p_Location->AreaDescriptionDisplay();
    }

    if (command == "inventory" || command == "show inventory") {
        cout << "--YOUR INVENTORY------" << endl;
        vector<string>::iterator iter;
        for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
            cout << "~" << *iter << "" << endl;
        }
        cout << "----------------------" << endl;
        return;
    }

    if (check2 == "go") {
        if (command == "go north") {
            if (p_Location->north != nullptr) {
                cout << "You head to the north." << endl;
                p_Location = p_Location->north;
            }
            else cout << "There is no path to go that way." << endl;
        }
        else if (command == "go south") {
            if (p_Location->south != nullptr) {
                cout << "You head to the south." << endl;
                p_Location = p_Location->south;
            }
            else cout << "There is no path to go that way." << endl;
        }
        else if (command == "go east") {
            if (p_Location->east != nullptr) {
                if (!p_Location->east->locked) {
                    cout << "You head to the east." << endl;
                    p_Location = p_Location->east;
                }
                else if (p_Location->east->locked) {
                    if (find(inventory.begin(), inventory.end(), "bronze key") != inventory.end()) {
                        cout << "You have unlocked the door with the Bronze Key Moe gave to you." << endl;
                        p_Location->east->locked = false;
                        cout << "After unlocking the door, you move through to the east." << endl;
                        p_Location = p_Location->east;
                    }
                    else cout << "The door to the next room seems to be locked, there has to be a key around here somewhere." << endl;
                }
            }
            else cout << "There is no path to go that way." << endl;
        }
        else if (command == "go west") {
            if (p_Location->west != nullptr) {
                cout << "You head to the west." << endl;
                p_Location = p_Location->west;
            }
            else cout << "There is no path to go that way." << endl;
        }
        else cout << "Invalid Direction! (go North, South, East, West)" << endl;
    }

    if (check4 == "take")
    {
        if (command == "take sword" || command == "take black sword" || command == "take the black sword")
        {
            p_Location->lakefront->grabBlade();
            if (p_Location->lakefront->pickedUpSword)
            {
                inventory.push_back("the black sword");
                return;
            }
            else
            {
                return;
            }
        }
        else {

            string item = command.substr(5);

            vector<string>::iterator iter;
            for (iter = p_Location->items.begin(); iter != p_Location->items.end(); ++iter) {
                if (iter != p_Location->items.end() && (*iter == item)) {
                    TakeItem(item);
                    p_Location->removeItem(item);
                    return;
                }
                else cout << item << " is not in this room" << endl;
            }
        }
    }

    if (check4 == "drop")
    {
        string item = command.substr(5);
        DropItem(item);
    }

    if (check11 == "investigate")
    {
        if (p_Location->portal)
        {
            if (command == "investigate platform")
            {
                p_Location->portal->portalInvestigation();
            }
        }
        else if (p_Location->lakefront)
        {
            if (command == "investigate body" || command == "investigate corpse")
            {
                p_Location->lakefront->InvestigateSword();
            }
        }
        else if (p_Location->swordPedestal)
        {
            if (command == "investigate pedestal")
            {
                p_Location->swordPedestal->InvestigatePedestal();
            }
        }
    }

    if (check4 == "talk")
    {
        if ((find(inventory.begin(), inventory.end(), "the black sword") != inventory.end()) && (command == "talk to sword" || command == "talk to the black sword"))
        {
            cout << "Yes! Let us go and destroy some evil! Go go go!" << endl;
        }
        else if (p_Location->npc)
        {
            if (command == "talk to moe" || command == "talk to skeleton")
            {
                p_Location->npc->InteractMoe();
            }
        }
        else cout << "Why are you talking to yourself..?" << endl;
    }

    if (check4 == "give")
    {
        if (command == "give to moe" || command == "give to skeleton")
        {
            string item;
            cout << "Want to give me something, do you? What is it?: ";
            getline(cin, item);
            if ((find(inventory.begin(), inventory.end(), "golden ring") != inventory.end()) && (item == "golden ring" || item == "ring"))
            {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter)
                {
                    if (*iter == item)
                    {
                        iter = inventory.erase(iter);
                        cout << "You show Moe the '" << item << "'." << endl;
                        p_Location->npc->giveMoe();
                        inventory.push_back("bronze key");
                        return;
                    }
                }
            }
            else cout << "I don't want that junk! Find something better if you want my help!" << endl;
        }
    }

    if (check5 == "place")
    {
        cout << "Place where?: ";
        string place;
        getline(cin, place);

        if (place == "platform" && p_Location->portal)
        {
            cout << "Place what?: ";
            string item;
            getline(cin, item);

            if (item == "green orb" && (find(inventory.begin(), inventory.end(), "green orb") != inventory.end()))
            {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter)
                {
                    if (*iter == item)
                    {
                        iter = inventory.erase(iter);
                        p_Location->portal->ActivatePortal(item);
                        return;
                    }
                }
            }
            else cout << "You can't place that there." << endl;
        }
        else if (place == "alter" && p_Location->paperAlter)
        {
            cout << "Place what?: ";
            string item;
            getline(cin, item);

            if (item == "strange scroll" && (find(inventory.begin(), inventory.end(), "strange scroll") != inventory.end())) {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
                    if (*iter == item) {
                        iter = inventory.erase(iter);
                        p_Location->paperAlter->placePaper();
                        return;
                    }
                }
            }
            else cout << "You can't place that there." << endl;
        }
        else if (place == "pedestal" && p_Location->swordPedestal)
        {
            cout << "Place what?: ";
            string item;
            getline(cin, item);

            if (item == "the black sword" && (find(inventory.begin(), inventory.end(), "the black sword") != inventory.end())) {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
                    if (*iter == item) {
                        iter = inventory.erase(iter);
                        p_Location->swordPedestal->PlaceSword();
                        inventory.push_back("blue orb");
                        return;
                    }
                }
            }
            else cout << "You can't place that there." << endl;
        }
        else if (place == "green slot" && p_Location->door)
        {
            cout << "Place what?: ";
            string item;
            getline(cin, item);

            if (item == "green orb" && (find(inventory.begin(), inventory.end(), "green orb") != inventory.end())) {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
                    if (*iter == item) {
                        iter = inventory.erase(iter);
                        p_Location->door->placeGreen();
                        return;
                    }
                }
            }
            else cout << "You can't place that there." << endl;
        }
        else if (place == "red slot" && p_Location->door)
        {
            cout << "Place what?: ";
            string item;
            getline(cin, item);

            if (item == "red orb" && (find(inventory.begin(), inventory.end(), "red orb") != inventory.end())) {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
                    if (*iter == item) {
                        iter = inventory.erase(iter);
                        p_Location->door->placeRed();
                        return;
                    }
                }
            }
            else cout << "You can't place that there." << endl;
        }
        else if (place == "blue slot" && p_Location->door)
        {
            cout << "Place what?: ";
            string item;
            getline(cin, item);

            if (item == "blue orb" && (find(inventory.begin(), inventory.end(), "blue orb") != inventory.end())) {
                vector<string>::iterator iter;
                for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
                    if (*iter == item) {
                        iter = inventory.erase(iter);
                        p_Location->door->placeBlue();
                        return;
                    }
                }
            }
            else cout << "You can't place that there." << endl;
        }
        else cout << "You can't place anything there." << endl;
    }

    if (check8 == "retrieve")
    {
        if (command == "retrieve green orb" && p_Location->portal && p_Location->portal->portalActive)
        {
            p_Location->portal->RetrieveOrb();
            inventory.push_back("green orb");
        }
        else if (command == "retrieve green orb" && p_Location->door)
        {
            p_Location->door->retrieveGreen();
            inventory.push_back("green orb");
        }
        else if (command == "retrieve red orb" && p_Location->door)
        {
            p_Location->door->retrieveRed();
            inventory.push_back("red orb");
        }
        else if (command == "retrieve blue orb" && p_Location->door)
        {
            p_Location->door->retrieveBlue();
            inventory.push_back("blue orb");
        }
        else cout << "Nothing to retrieve." << endl;
    }

    if (check5 == "enter")
    {
        if (command == "enter portal" && (p_Location->portal->portalActive && !p_Location->portal->enteredPortal))
        {
            cout << "You slowly walk towards the gleaming portal. As you reach towards it, you feel as if you're being sucked into it. In mere seconds, the portal has swallowed you, and you have feel yourself falling." << endl;
            p_Location->portal->enteredPortal = true;
            p_Location = p_Location->portalArea;
        }
        else if (command == "enter portal" && (p_Location->portal->portalActive && p_Location->portal->enteredPortal))
        {
            cout << "You enter the portal again." << endl;
            p_Location = p_Location->portalArea;
        }
        else if (command == "enter barrier" && p_Location->riddles)
        {
            if (!p_Location->riddles->introductionSeen)
            {
                p_Location->riddles->barrier();
                if (p_Location->riddles->riddle1Answered && p_Location->riddles->riddle2Answered && p_Location->riddles->riddle3Answered)
                {
                    inventory.push_back("green orb");
                    return;
                }
            }
            else if (p_Location->riddles->introductionSeen)
            {
                p_Location->riddles->Riddles();
                if (p_Location->riddles->riddle1Answered && p_Location->riddles->riddle2Answered && p_Location->riddles->riddle3Answered)
                {
                    inventory.push_back("green orb");
                    return;
                }
            }
        }
    }

    if (check5 == "close" || check7 == "sheathe")
    {
        if (command == "close sword" || command == "sheathe sword" || command == "close black sword" || command == "sheathe black sword" || command == "close the black sword" || command == "sheathe the black sword")
        {
            p_Location->lakefront->swordClose();
        }
    }

    if (check4 == "loot")
    {
        if ((command == "loot dragon" || command == "loot red dragon") && p_Location->redDragon->dragonDead && !p_Location->redDragon->lootedDragon)
        {
            cout << "You walk over to the corpse of the dragon and begin to search it's gleaming ornaments." << endl
                << "As you search, nothing seems to be too noteworthy until your eyes come across a strange ring the dragon was wearing on one of it's back claws." << endl
                << "A deep, crimson orb, similar to the green orb you received from the riddle statues, sits atop the ring." << endl
                << "You decide that the similarity to the green orb is noteworthy, and take the orb from atop it's ring place." << endl;
            cout << "\nYOU OBTAINED THE RED ORB\n" << endl;
            inventory.push_back("red orb");
            p_Location->redDragon->lootedDragon = true;
        }
        else cout << "Nothing to loot here." << endl;
    }
}

void Player::TakeItem(string item) {
    p_Location->removeItem(item);
    inventory.push_back(item);
    cout << "Picked up the " << item << "." << endl;
}

void Player::DropItem(std::string item) {
    vector<string>::iterator iter;
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        if (*iter == item)
        {
            iter = inventory.erase(iter);
            cout << "Dropped the " << item << "." << endl;
            p_Location->addItem(item);
            return;
        }
    }
    cout << "'" << item << "' is not in your inventory." << endl;
}

void Player::ReceiveItem(const std::string& item) {
    inventory.push_back(item);
    cout << "Received the '" << item << "'." << endl;
}

void Player::RemoveItem(const string& item) {
    vector<string>::iterator iter;
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        if (*iter == item)
        {
            iter = inventory.erase(iter);
            cout << "You lost the '" << item << "'." << endl;
            return;
        }
    }
}
