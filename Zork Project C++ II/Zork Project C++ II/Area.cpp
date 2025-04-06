#include <iostream>
#include <string>
#include <vector>
#include "Area.h"

using std::cout;
using std::endl;
using std::vector;

Area::Area(string name, string desc, bool locked, bool hasVisited)
{
    AreaName = name;
    AreaDescription = desc;
}

string Area::getAreaName() {
    return AreaName;
}

void Area::AreaNameDisplay()
{
    cout << "Location: " << AreaName << endl;
    if (!items.empty())
    {
        cout << "You see some items in this room: " << endl;
        for (string& item : items)
        {
            cout << "--" << item << "--" << endl;
        }
    }
}

void Area::AreaDescriptionDisplay() {
    cout << "This are is called the " << AreaName << endl;
    cout << AreaDescription << endl;
    if (!items.empty())
    {
        cout << "You see some items in this room: " << endl;
        for (string& item : items)
        {
            cout << "--" << item << "--" << endl;
        }
    }
}

void Area::AreaInfo() {
    cout << AreaDescription << endl;
    if (!items.empty())
    {
        cout << "You see some items in this room: " << endl;
        for (string& item : items)
        {
            cout << "--" << item << "--" << endl;
        }
    }
    cout << "You take note of the " << AreaName << "." << endl;
}

void Area::addItem(string item)
{
    items.push_back(item);
}

void Area::removeItem(string item)
{
    vector<string>::iterator iter;
    for (iter = items.begin(); iter != items.end(); ++iter)
    {
        if (*iter == item)
        {
            iter = items.erase(iter);
            return;
        }
    }
}
