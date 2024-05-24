#pragma once
#include <iostream>
#include "inventory.h"
using namespace std;

class HandHeldInventory;
class Item;

class InventoryIterator{
    public:
    virtual bool isDone()=0;
    virtual void next()=0;
    virtual Item current()=0;
};

class HandHeldInventoryIterator : public InventoryIterator{
    private:
    HandHeldInventory* hi; //here we use HandHeldInventory concrete impl instead of IInventory abstract class because HandHeldInventoryIterator is also concrete 
    int countOfItemsReturned;
    public:
    HandHeldInventoryIterator(HandHeldInventory* hi);
    bool isDone() override;
    void next() override;
    Item current() override;
};