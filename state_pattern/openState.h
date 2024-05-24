#pragma once
#include <iostream>
#include "state.h"
#include "gate.h"

class OpenGateState:public GateState{
    private:
    Gate* gate;
    public:
    OpenGateState(Gate* g);
    void enter() override;
    void payok() override;
    void pay() override;
    void payfailed() override;
};