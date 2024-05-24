#include <iostream>
using namespace std;

//consider these classes as part of a game, so there is inventory of items and there are few items that are hand held, so we have seperate
//inventory for them. If Player wants to see list of items then we can use iterator. we can also have LegHeldInventory and its iterator

class Item{
    public:
    string name;
    Item(string name):name(name){}
};

class InventoryIterator{
    public:
    virtual bool isDone()=0;
    virtual void next()=0;
    virtual Item current()=0;
};

class HandHeldInventoryIterator;

class IInventory{
    public:
    virtual InventoryIterator* getIterator()=0;
};

class HandHeldInventory:IInventory{
    public:
    Item right;
    Item left;
    HandHeldInventory(Item r,Item l):right(r),left(l){}
    InventoryIterator* getIterator() override{
        return new HandHeldInventoryIterator(this);
    }
};

class HandHeldInventoryIterator : public InventoryIterator{
    private:
    HandHeldInventory* hi; //here we use HandHeldInventory concrete impl instead of IInventory abstract class because HandHeldInventoryIterator is also concrete 
    int countOfItemsReturned;
    public:
    HandHeldInventoryIterator(HandHeldInventory* hi):hi(hi),countOfItemsReturned(0){}
    bool isDone() override{
        return countOfItemsReturned<2; //we have only 2 items right and left
    }
    void next() override{
        countOfItemsReturned++;
    }
    Item current() override{
        if(countOfItemsReturned == 0){return hi->right;}
        else if(countOfItemsReturned == 1){return hi->left;}
    }
};

void iterateOverAnyInventory(InventoryIterator* iter){
    while(!iter->isDone()){
        cout<<iter->current().name;
        iter->next();
    }
}

int main(){
    Item mobile{"mobile"};
    Item rod{"metal rod"};
    HandHeldInventory hi{mobile,rod};
    iterateOverAnyInventory(hi.getIterator());
    return 0;
}