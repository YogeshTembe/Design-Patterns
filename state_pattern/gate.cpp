#include "gate.h"
#include "closedState.h"

Gate::Gate(){
    state = new ClosedGateState(this);
}

void Gate::enter(){
    state->enter();
}
void Gate::pay(){
    state->pay();
}
void Gate::payok(){
    state->payok();
}
void Gate::payfailed(){
    state->payfailed();
}
void Gate::changeState(GateState* newstate){
    state = newstate;
}   