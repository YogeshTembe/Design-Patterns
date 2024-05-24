#pragma once
#include <iostream>

class GateState{
    public:
    virtual void enter()=0;
    virtual void pay()=0;
    virtual void payok()=0;
    virtual void payfailed()=0;
};