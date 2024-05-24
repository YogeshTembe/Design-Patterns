#include "inventoryIterator.h"

HandHeldInventoryIterator::HandHeldInventoryIterator(HandHeldInventory* hi):hi(hi),countOfItemsReturned(0){}

bool HandHeldInventoryIterator::isDone(){
    return countOfItemsReturned>2; //we have only 2 items right and left
}

void HandHeldInventoryIterator::next(){
    countOfItemsReturned++;
}

Item HandHeldInventoryIterator::current(){
    if(countOfItemsReturned == 0){return hi->right;}
    else if(countOfItemsReturned == 1){return hi->left;}
    return Item{"default"};
}