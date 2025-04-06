#include<iostream>
#include<string>
#include<vector>
#include "Moe.h"
#include "Portal.h"
#include "RiddleStatues.h"
#include "Lake.h"
#include "Alter.h"
#include "Dragon.h"
#include "Pedestal.h"
#include "FinalDoor.h"
#pragma once

using std::string;
using std::vector;

class Area
{
public:
    Area(string name, string desc, bool locked, bool hasVisited);
    bool locked;
    bool hasVisited;
    Moe* npc;
    Portal* portal;
    RiddleStatues* riddles;
    Lake* lakefront;
    Alter* paperAlter;
    Dragon* redDragon;
    Pedestal* swordPedestal;
    FinalDoor* door;
    void AreaInfo();
    string getAreaName();
    void AreaNameDisplay();
    void AreaDescriptionDisplay();
    void addItem(string item);
    void removeItem(string item);
    vector<string> items;
    Area* north;
    Area* south;
    Area* east;
    Area* west;
    Area* portalArea;


private:
    string AreaName;
    string AreaDescription;
};

