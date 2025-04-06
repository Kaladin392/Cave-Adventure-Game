#pragma once
using std::string;
class Portal {
public:
    Portal();
    bool portalActive;
    bool enteredPortal;
    bool activated;

    void ActivatePortal(const string& item);
    void RetrieveOrb();
    void portalInvestigation();
};

