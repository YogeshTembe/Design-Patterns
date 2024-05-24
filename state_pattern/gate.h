#pragma once
#include <iostream>
#include "state.h"
using namespace std;

class Gate{
    private:
    GateState* state;
    public:
    Gate();

    void enter();
    void pay();
    void payok();
    void payfailed();
    void changeState(GateState* newstate);
};