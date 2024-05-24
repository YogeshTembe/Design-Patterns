#include "closedState.h"
#include "processingState.h"

ClosedGateState::ClosedGateState(Gate* g):gate(g){}

void ClosedGateState::enter(){
    cout<<"ClosedGateState::enter"<<endl;
}

void ClosedGateState::payok(){
    cout<<"ClosedGateState::payok"<<endl;
}

void ClosedGateState::pay(){
    cout<<"ClosedGateState::pay"<<endl;
    gate->changeState(new ProcessingGateState(this->gate));
}

void ClosedGateState::payfailed(){
    cout<<"ClosedGateState::payfailed"<<endl;
}