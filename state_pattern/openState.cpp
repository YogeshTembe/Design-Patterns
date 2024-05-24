#include "openState.h"
#include "closedState.h"

OpenGateState::OpenGateState(Gate* g):gate(g){}

void OpenGateState::enter(){
    cout<<"OpenGateState::enter"<<" let user in"<<endl;
    gate->changeState(new ClosedGateState(this->gate));
}

void OpenGateState::payok(){
    cout<<"OpenGateState::payok"<<endl;
}

void OpenGateState::pay(){
    cout<<"OpenGateState::pay"<<endl;
}

void OpenGateState::payfailed(){
    cout<<"OpenGateState::payfailed"<<endl;
}