#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Player.h"

using namespace std;

int main() {

    Map GameMap;
    Player hero;
    bool running = true;
    bool isDead = false;
    bool dragonAwakened = false;
    bool swordNotedPedestal = false;
    bool dragonIsDead = false;

    //string mode;
    //cout << "start in play mode or debug mode?:";
    //cin >> mode;
    //if (mode == "debug" || mode == "d") {
    //    cout << "\nRUNNING IN DEBUG MODE\n\n";
    //    hero.inventory.push_back("the black sword");
    //    hero.inventory.push_back("strange scroll");
    //    hero.inventory.push_back("bronze key");
    //    hero.inventory.push_back("golden ring");
    //    hero.inventory.push_back("green orb");
    //    hero.inventory.push_back("red orb");
    //    hero.inventory.push_back("blue orb");
    //}
    //else cout << "\nRUNNING IN PLAY MODE\n\n";
    //cin.ignore();

    cout << "\nWelcome to 'Cave Adventure!!!'" << endl;
    cout << "\nCOMMANDS:\n*[go (main cardinal direction)]: move throughout the map\n*[look]: shows area description\n*[inventory]: displays player inventory\n*[commands]: displays command list\n*[take (item)]: add area item into player inventory\n*[drop (item)]: drop item from player inventory into the room\n*[talk to (object)]: attempt to talk to something\n*[give to (object) -> (item)]: attempt to give an item to something\n*[enter (object)]: attempt to enter something\n*[place -> (object) -> (item)]: attempt to place an item onto an object\n" << endl;
    do {
        if (hero.p_Location->getAreaName() == "Door")
        {
            if (hero.p_Location->door->placedGreen && hero.p_Location->door->placedRed && hero.p_Location->door->placedBlue)
            {
                cout << "\nAs you house the final orb in it's place, the door shutters. You back away as you hear the door jutter and creak loudly as stone grates stone." << endl
                    << "The door then begins to open slowly, revealing true, natural light. Your heart beats faster as the light crosses your face, and you accept the heat of a sun you have not had the pleasure of seeing." << endl
                    << "Soon, the doors stop, opened, beckoning, and so you walk forward, outside of the cave at last." << endl
                    << "Exiting through the door, you find yourself in a vast vibrant expanse. Green plains paint the terrain, light forests speckle the earth. Old buildings dot the landscape, just waiting to be explored." << endl
                    << "It seems you have exited the cave into an even bigger world than before. You decide to keep treading on, towards new and unknowable adventures..." << endl
                    << "\nCAVE ADVENTURE II: THE SECOND ONE - COMING SOON\n(due to recent events, progress has been suspended indefinitely)\n\n"
                    << "THANKS FOR PLAYING!!!" << endl;
                cout << "   -ELIJAH JACOB LAWYER" << endl;
                system("pause");
                return 0;
            }
        }

        if (hero.p_Location->getAreaName() == "Strange Alter")
        {
            if (hero.p_Location->paperAlter->paperPlaced)
            {
                dragonAwakened = true;
            }
        }

        if (hero.p_Location->getAreaName() == "Large Chamber") {
            if (hero.p_Location->redDragon) {
                if (!hero.p_Location->redDragon->dragonDead && dragonAwakened) {
                    cout << "\nAs you look around, another of those deafening roars is sounded above you. As you crane your neck to the ceiling, your heart catches in your throat." << endl
                        << "An enormous, red, towering DRAGON drops from the ceiling with a gigantic 'THUD'." << endl
                        << "As your eyes race to catch up with the figure, you already notice the hulking beast racing towards you, a face of pure fury etched across it's reptilion visage." << endl
                        << "You must think of what to do, and do it NOW, otherwise this dragon will kill you! You decide to: " << endl << "> ";
                    string action;
                    getline(cin, action);
                    if ((find(hero.inventory.begin(), hero.inventory.end(), "the black sword") != hero.inventory.end()) &&
                        (action == "draw black sword" || action == "draw the black sword" ||
                            action == "draw the sword" || action == "draw sword")) {
                        cout << "\nWith no other options clear and your life certainly on the line, you reach down to your belt and fully unsheathe the black longsword with your right hand." << endl
                            << "As you do, pain jolts up the arm now wielding the sword. Black lines now envelope your veins as the sword seems to scream in your head 'DIE EVIL MONSTER'" << endl
                            << "With blinding speed, your arm seems to move on it's own, throwing the blade upwards towards the approaching dragons belly in a powerful slash." << endl
                            << "Just as you pull back, you hear a scream of pain from the beast as if falls behind you with a 'BOOM'." << endl
                            << "Before even peaking to make sure the dragon is done, you sheathe the black sword as quickly as you drew it." << endl
                            << "Dropping to your knees, you clutch your right arm as it bursts with pain, the black veins slowly subsiding and sliding back with the sword into is scabbard." << endl
                            << "After resting for a moment, you get up and peer behind you at the huge, now seemingly dead, dragon. The only thing that pushes your head away from the pain you're feeling is the dragon itself" << endl
                            << "A magnificent creature if you have ever seen one, the dragon was great and red and seemed to have caked itself in jewelery and treasure. Everywhere around it are gems and gold rings decorating it from head to toe." << endl
                            << "Perhaps looting the body could yield something interesting?\n" << endl;
                        hero.p_Location->redDragon->dragonDead = true;
                        dragonIsDead = true;
                    }
                    else {
                        cout << "\nWhat you decided to do barely entered your head as the dragons mouth slams into you, and with one chomp, your body breaks into two and everything goes black.\n" << endl;
                        isDead = true;
                    }
                }
                else if (hero.p_Location->redDragon->dragonDead && !hero.p_Location->redDragon->lootedDragon)
                    cout << "\nThe majestic red dragon lies dead, the remnants of the black swords cuts still evident... The dragon is still wearing many ornaments. Perhaps you should loot the dragon and see what you can find?" << endl;
                else if (dragonIsDead) cout << "\nThe corpse of the dragon seems a sad sight in the empty cavern...";
            }
        }

        if (hero.p_Location->getAreaName() == "Crystal Cavern" && !swordNotedPedestal && (find(hero.inventory.begin(), hero.inventory.end(), "the black sword") != hero.inventory.end()))
        {
            if (!dragonIsDead) {
                cout << "\nThe sword hums on your waist as you re-enter the crystalline cavern. It seems to be reacting to the pedestal in the center of the room." << endl
                    << "Voice in the Sword: 'Hmm, something feels right about this place... Perhaps that pedestal is where he said he would come back for me...'" << endl
                    << "The sword seems to rumble to itself." << endl
                    << "Voice in the Sword: 'Yes, I think I need to be on this pedestal... But... Not yet, I think. There is EVIL somewhere in this cave that needs smiting! Yes, I don't think once I enter that pedestal you can take me out again without Vasher's help! Let's go find that EVIL aura before you do that!'\n" << endl;
                swordNotedPedestal = true;
            }
            else {
                cout << "\nThe sword hums on your waist as you re-enter the crystalline cavern. It seems to be reacting to the pedestal in the center of the room." << endl
                    << "Voice in the Sword: 'Hmm, something feels right about this place... Perhaps that pedestal is where he said he would come back for me...'" << endl
                    << "The sword seems to rumble to itself." << endl
                    << "Voice in the Sword: 'Yes yes. I think after destroying that evil dragon I am ready to wait for him to return. Place me into that pedestal, will ya!'\n" << endl;
                swordNotedPedestal = true;
            }
        }

        if (!hero.p_Location->hasVisited)
        {
            cout << endl;
            hero.p_Location->AreaInfo();
            hero.p_Location->hasVisited = true;
            cout << endl;
        }
        else
        {
            cout << endl;
            hero.p_Location->AreaNameDisplay();
            cout << endl;
        }

        if (!isDead)
        {
            string command;
            cout << "> ";
            getline(cin, command);
            transform(command.begin(), command.end(), command.begin(), ::tolower);
            if (command == "go south" && hero.p_Location->getAreaName() == "Mossy Passageway")
            {
                cout << "\nAs you step through the vines you begin to ride down a muddy slide. \nAs you pick up speed, you suddenly feel yourself thrust into the air, landing once again in a pool of dirty water. \nNot a lake this time however, as poking your head above the murcky water reveals a familiar sight. \nYou have landed in the muddy pond outside of Moe's House...\nAs you slowly get out of the pond and attempt to slap yourself dry, you swear you can hear Moe's metallic chuckling from his porch." << endl;
            }

            if (command == "quit") running = false;
            else hero.Commands(command);

            
        }

    } while (running && !isDead);

    if (!running) {
        cout << "\n\nYou have exited the game..." << endl;
    }
    else if (isDead)
    {
        cout << "\n\nYou have died...\nA WEAPON IS REALLY THE ONLY THING SUITED TO FIGHTING A DRAGON, DON'T YOU THINK?\nDo better..." << endl;
    }

    system("pause");
    return 0;
}