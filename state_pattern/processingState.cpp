#include "closedState.h"
#include "processingState.h"
#include "openState.h"

ProcessingGateState::ProcessingGateState(Gate* g):gate(g){}

void ProcessingGateState::enter(){
    cout<<"ProcessingGateState::enter"<<endl;
}

void ProcessingGateState::payok(){
    cout<<"ProcessingGateState::payok"<<" let user in"<<endl;
    gate->changeState(new OpenGateState(this->gate));
}

void ProcessingGateState::pay(){
    cout<<"ProcessingGateState::pay"<<endl;
}

void ProcessingGateState::payfailed(){
    cout<<"ProcessingGateState::payfailed"<<" stop user"<<endl;
    gate->changeState(new ClosedGateState(this->gate));
}