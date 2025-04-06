#include <iostream>
#include "Lake.h"

using std::cout;
using std::endl;

Lake::Lake() {
    pickedUpSword = false;
    closedSword = false;
}

void Lake::swordClose() {
    if (!pickedUpSword && !closedSword) {
        cout << "\nPushing any doubts down into your gut, you lean with one leg to the side, and using the tip of your right foot, slide the sword back into the sheathe." << endl
            << "As you do, the dark tendrils snake their way back into the blade, closing themselves within along with the sword.\n" << endl;
        closedSword = true;
    }
}

void Lake::InvestigateSword() {
    if (!pickedUpSword && !closedSword) {
        cout << "\nAs you look at the figure you notice many things at once." << endl
            << "The most notable being the state of the body, and the strange weapon in their hands." << endl
            << "The body seems to be dressed in what appears to be lab attire, a white lab coat over neat clothes, now mucked and dirty from the ground they lay upon." << endl
            << "The expression is hard to read over a face seemingly drained of all life, but surprise seems the most evident." << endl
            << "And now your eyes are drawn to the sword, and as you notice it, more strange details enter your mind." << endl
            << "The sword is partly raised from it's silver sheathe. The sheathe though, completely contrasts with the blade itself." << endl
            << "Both blade, pommel, and hilt are completely black. From what can be seen of the blade peaking out of it's sheathe, it seems a typical thin longsword, but the color is haunting." << endl
            << "Adding deeper to the horror of the blades appearance are the black, serpentine tendrils of darkness creeping from within it's sheathe, wrapping themselves around the corpse that lay beside it." << endl
            << "The sight makes you immediately uneasy. Something strange and dark is at play here...\n" << endl;
    }
    else if (!pickedUpSword && closedSword) {
        cout << "\nThe sword now lays at the feet of the corpse closed within it's sheathe, now no tendrils of darkness encircle the blade or the corpse.\n" << endl;
    }
    else {
        cout << "\nThe dead person still lays under the tree, the look of surprise still etched on their face.\n" << endl;
    }
}

void Lake::grabBlade() {
    if (!closedSword)
    {
        cout << "\nYou reach down for the wicked blade, and grab at it's hilt. Just as you do, a shutter of complete and utter pain writhes through your arm." << endl
            << "As you rise to your feet, you find it impossible to let go. Gazing down at your arm, you notice your veins go dark, then as black as the pits of darkness around you." << endl
            << "All of your energy is being drained. No, not just your energy, all of your life is breaking apart, being absorbed and stolen by this foul blade." << endl
            << "As your energy depletes, keeping your eyes open becomes just as much of a chore as standing. You drop to your knees and fall, planking on top of the other body." << endl
            << "And just before your eyes close for good, you hear strange words enter your mind." << endl
            << "Voice: 'DESTROY EVIL'." << endl
            << "Then all goes black.\n" << endl
            << "With a shudder your mind opens up. You are once again standing over the corpse and the sword, everything where it was before." << endl
            << "It's as if what just happened to you was a vision or a dream... Some kind of warning... It seems if you are set on picking up that sword, you better sheathe it first...\n" << endl;
    }
    else {
        cout << "\nYou grab the sheathe of the enclosed blade and lift the sword, freeing it from the corpses grasp." << endl
            << "After studying the sword for a moment, you decide to slide the weapon into the belt of your pants, and as you do, something makes you almost drop the blade in shock." << endl
            << "'Hello' a cheerful voice says into your mind. 'Would you like the destroy some evil today?'" << endl;
        cout << "\nYOU HAVE OBTAINED THE BLACK SWORD\n" << endl;
        pickedUpSword = true;
    }
}
