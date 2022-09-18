#include<iostream>
using namespace std;

class ITarget{
    public:
        virtual void request()=0;
};

class Adaptee{
    public:
        void specificRequest(){
            cout<<"This is a specific request";
        }
};

class Adapter:public ITarget{
    public:
        Adaptee* adaptee;
        Adapter(Adaptee* a){
            adaptee=a;
        }
        void request(){
            //here we make request compatible with adaptee's specific request... adaptee could be external library or something
            adaptee->specificRequest();
        }
};

//Actually client code wants to contact adaptee's specific request but could not directly contact bcoz of incompatability of some kind so we introduce ITarget interface and adapter between them
int main(){
    //client code
    Adapter* target=new Adapter(new Adaptee());
    target->request();
    return 0;
}