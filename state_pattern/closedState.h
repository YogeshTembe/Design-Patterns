#pragma once
#include <iostream>
#include "state.h"
#include "gate.h"

class ClosedGateState:public GateState{
    private:
    Gate* gate;
    public:
    ClosedGateState(Gate* g);
    void enter() override;
    void payok() override;
    void pay() override;
    void payfailed() override;
};