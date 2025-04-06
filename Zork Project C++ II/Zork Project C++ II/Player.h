#include <iostream>
#include <vector>
#include "Map.h"
#pragma once

using std::string;
using std::vector;

class Player : public Map {
public:
    Player();
    Area* p_Location;
    vector<string> inventory;
    void TakeItem(string item);
    void DropItem(string item);
    void ReceiveItem(const string& item);
    void RemoveItem(const string& item);
    void Commands(const string& command);
};

