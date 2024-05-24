#include "inventory.h"
using namespace std;

void iterateOverAnyInventory(InventoryIterator* iter){
    while(!iter->isDone()){
        cout<<iter->current().name<<endl;
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