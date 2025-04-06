#include "Map.h"

Map::~Map() {
    delete MapStart;
}

Map::Map() {
    /*1*/Area* start = new Area("Chasm Floor", "As you open your eyes, you're greeted with only the sight shown by nearby torchlight. \nAs you look around, you find yourself in a dreary cavern, with no end in sight. \nWhile wondering where you are or how you go here, you hear a menacing roar that causes you to shoot to your feet. \nLooking around reveals nothing that could have made that horrific noise, but all you know for sure is that you need to find your way out of this cave, and fast. \nYou grab the nearby torch, and begin wondering which direction to go... \n", false, false);
    MapStart = start;
    /*2*/Area* skeleton = new Area("Mud Home", "You enter this side of the cavern through a thick soppy mud.\nIn this distance you notice a great muddy pond with strange insects buzzing aroung it.\nAs you trudge further, light greets you through what looks to be a window of a house carved from mud and clay.\nOn what appears to be the porch, you notice something truly bizarre... A bare skeleton is sitting on a strewn lawn chair, relaxing.\nThe skeleton appears to be gazing down at a stone plate in their hands, as if reading it like a book...", false, false);
    Moe* moe = new Moe();
    skeleton->npc = moe;
    /*3*/Area* fossil = new Area("Fossilized Passage", "As you follow this wide crevasse, you notice the torch you hold enlighten shapes on the walls and ceiling...\nLooking closer, you notice what they are... Dozens... No, hundreds of fossilized bones.\nTaking your gaze from the dead creatures around, you notice light coming from the other side of the passage.\n", false, false);
    /*4*/Area* bats = new Area("Bat Roost", "Coming into this passageway, you notice hundreds, if not thousands, of bats sitting upon the cave ceiling, their wings folded tightly. \nAs the bats flutter and move, the sound permeates your body.", false, false);
    /*5*/Area* riddle = new Area("Riddle Room", "Leaving the bat roost, you lay your eyes upon a group of three statues, standing in a line. \nThe leftmost, a armored knight, his blade valiantly displayed grasped in both hands. \nThe one in the middle is wearing what appears to be a jesters outfit, the face smiling jovially. \nThe last is a women, standing tall and elegant, hands held neatly at her center. \nDespite them being made of solid stone, you have strange sense of being watched. \nBefore the three statues is a grounded circular barrier surrounded by green light. \nThe statues seem to beckon you forth...\n", false, false);
    RiddleStatues* riddles = new RiddleStatues();
    riddle->riddles = riddles;
    /*6*/Area* chamber = new Area("Large Chamber", "You enter a massive chamber that's expanse seems so endless that it distorts your vision. \nA giant gate is visible just within eyeshot, mirroring the entrance to the chamber. \nDispersed upon the ground are large, red scales. \nYou wonder what sort of creature they came from...\n", false, false);
    Dragon* dragon = new Dragon();
    chamber->redDragon = dragon;
    /*7*/Area* pedestal = new Area("Crystal Cavern", "Entering towards the light, you stumble upon a vern filled with glimmering, magnificent crystals. \nThe disorienting light spawns from a large, certainly man-made lamp that seats the middle of the ceiling. \nUnder the light, a mysterious pedestal awaits.\n", false, false);
    Pedestal* swordPedestal = new Pedestal();
    pedestal->swordPedestal = swordPedestal;
    /*8*/Area* orbDoor = new Area("Door", "The instant you enter the room, you notice a giant stone door across the entryway. \nTo the bottom of the door, you notice three equal, spherical slots, each with a different color, green, red, then blue.\nIt seems the slots are awaiting something to be placed within...", false, false);
    FinalDoor* door = new FinalDoor();
    orbDoor->door = door;
    /*9*/Area* FREEDOM = new Area("", "", false, false);
    /*10*/Area* lab1 = new Area("Lab Entrance", "You criss-cross your way into what seems to be the first evidence of other humans since you awoke.\nA strange laboratory is before you, messy and cluttered.\nBooks and papers abound the floor and many tables. \nMost notably being an interesting red scroll in the center of the room...\n", false, false);
    lab1->addItem("strange scroll");
    /*11*/Area* lab2 = new Area("Laboratory", "As you wander further into the lab, you find another room, just as filthy as the last, still no signs of any of the scientists or workers who researched here. \nYou notice a closed door on the east of the room, next to it is a table with a single item on top... \nA flawless golden signet ring with a monarch butterfly motif etched around it's circumference.\n", false, false);
    lab2->addItem("golden ring");
    /*12*/Area* SLab = new Area("Secret Laboratory", "As you enter the previously locked room, you notice immediatly a strange, almost alien device...\nStone circles envelope to create what looks like a shperical stone archway.\nAttached to the sides are wires coming out of the walls and ceiling.\nIn the center of the room, is a tiny, stone platform.\n", true, false);
    SLab->locked = true;
    Portal* portal = new Portal();
    SLab->portal = portal;
    /*13*/Area* lake = new Area("Underground Lakefront", "You fall through the sky and feel a spike of cold as you drop into icy water. \nGaining your footing, you tread to the surface and grasp for land.\nAs you stand upon the shore, you notice where you are. \nA beautiful underwater lake is gleaming, water lighting up from astounding sunlight falling from the far reaching crevasse high, high above.\n In the center of the lake, connected to the lakefront via a long rocky walkway, is a single, living oak tree. \nThe pure natural beauty almost pokes a smile from your lips before you notice what's under the tree. \nThe dead body of a human, holding something in their hands...\n", false, false);
    Lake* lakefront = new Lake();
    lake->lakefront = lakefront;
    /*14*/Area* moss = new Area("Mossy Passageway", "The lake leaves your vision as you follow a moss-covered passageway. \nThe walls are damp and covered in a thick layer of moss. \nYou almost slip multiple times throughout your journey. \nAs you reach the end of the passageway, you notice two tunnels. The one to the east seems to enter a small, dark room. The passage to the south is covered by vines, but looks to head downwards, like a slide...\n", false, false);
    /*15*/Area* alter = new Area("Strange Alter", "On the other side of the mossy pathway is a small chambered room, barely wide enough for you to fit both hand spans within.\n A strange alter, made seemingly of bones and sinue is the only thing decorating this small room.\nThis alter gives you a strikingly bad feeling...\n", false, false);
    Alter* paperAlter = new Alter();
    alter->paperAlter = paperAlter;

    start->north = nullptr;
    start->south = nullptr;
    start->east = skeleton;
    start->west = fossil;

    skeleton->north = nullptr;
    skeleton->south = bats;
    skeleton->east = nullptr;
    skeleton->west = start;

    fossil->north = nullptr;
    fossil->south = nullptr;
    fossil->east = start;
    fossil->west = pedestal;

    bats->north = skeleton;
    bats->south = chamber;
    bats->east = riddle;
    bats->west = nullptr;

    riddle->north = nullptr;
    riddle->south = nullptr;
    riddle->east = nullptr;
    riddle->west = bats;

    chamber->north = bats;
    chamber->south = nullptr;
    chamber->east = nullptr;
    chamber->west = nullptr;

    pedestal->north = orbDoor;
    pedestal->south = lab1;
    pedestal->east = fossil;
    pedestal->west = nullptr;

    orbDoor->north = FREEDOM;
    orbDoor->south = pedestal;
    orbDoor->east = nullptr;
    orbDoor->west = nullptr;

    FREEDOM->north = nullptr;
    FREEDOM->south = orbDoor;
    FREEDOM->east = nullptr;
    FREEDOM->west = nullptr;

    lab1->north = pedestal;
    lab1->south = nullptr;
    lab1->east = lab2;
    lab1->west = nullptr;

    lab2->north = nullptr;
    lab2->south = nullptr;
    lab2->east = SLab;
    lab2->west = lab1;

    SLab->north = lake;
    SLab->south = nullptr;
    SLab->east = nullptr;
    SLab->west = lab2;
    SLab->portalArea = lake;

    lake->north = nullptr;
    lake->south = nullptr;
    lake->east = moss;
    lake->west = nullptr;

    moss->north = nullptr;
    moss->south = skeleton;
    moss->east = alter;
    moss->west = alter;

    alter->north = nullptr;
    alter->south = nullptr;
    alter->east = nullptr;
    alter->west = moss;
};
