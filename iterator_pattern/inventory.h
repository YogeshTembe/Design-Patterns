#pragma once
#include <iostream>
#include "inventoryIterator.h"
using namespace std;

class InventoryIterator;

class Item{
    public:
    string name;
    Item(string name);
};

class IInventory{
    public:
    virtual InventoryIterator* getIterator()=0;
};

class HandHeldInventory:IInventory{
    public:
    Item right;
    Item left;
    HandHeldInventory(Item r,Item l);
    InventoryIterator* getIterator() override;
};