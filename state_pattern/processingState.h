#pragma once
#include <iostream>
#include "state.h"
#include "gate.h"

class ProcessingGateState:public GateState{
    private:
    Gate* gate;
    public:
    ProcessingGateState(Gate* g);
    void enter() override;
    void payok() override;
    void pay() override;
    void payfailed() override;
};