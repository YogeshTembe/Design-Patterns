#include "inventory.h"
using namespace std;

Item::Item(string name):name(name){}

HandHeldInventory::HandHeldInventory(Item r,Item l):right(r),left(l){}

InventoryIterator* HandHeldInventory::getIterator(){
    return new HandHeldInventoryIterator(this);
}