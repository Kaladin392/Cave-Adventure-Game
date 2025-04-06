#pragma once
class RiddleStatues {
public:
    RiddleStatues();
    bool introductionSeen;
    bool riddle1Answered;
    bool riddle2Answered;
    bool riddle3Answered;
    bool exited;

    void barrier();
    void Riddles();
};

