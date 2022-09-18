#include<iostream>
#include <string>
using namespace std;

class beverage{
    public:
        virtual string getDescription()=0;
        virtual int getCost()=0;
};

class espresso:public beverage{
    public:
        string getDescription(){
            return ":espresso:";
        }
        int getCost(){
            return 2;
        }
};

class latte:public beverage{
    public:
        string getDescription(){
            return ":latte:";
        }
        int getCost(){
            return 4;
        }
};

class addOnDecorator:public beverage
{
    protected:
        beverage *b_beverage;
    public:
        addOnDecorator(beverage *b): b_beverage(b){}
        string getDescription(){
            return b_beverage->getDescription();
        }
        int getCost(){
            return b_beverage->getCost();
        }
};

class caramel:public addOnDecorator{
    public:
        caramel(beverage* b):addOnDecorator(b){
        }
        int getCost(){
            return b_beverage->getCost()+2;
        }
        string getDescription(){
            return b_beverage->getDescription()+":caramel:";
        }
        
};

class choco:public addOnDecorator{
    public:
        choco(beverage* b):addOnDecorator(b){}
        int getCost(){
            return b_beverage->getCost()+5;
        }
        string getDescription(){
            return b_beverage->getDescription()+":choco:";
        }
};

int main(){
    beverage* esp=new espresso();
    beverage* topping1=new caramel(esp);
    cout<<"with caramel topping"<<endl;
    cout<<topping1->getDescription()<<endl;
    cout<<topping1->getCost()<<endl;

    beverage* topping2=new choco(topping1);
    cout<<"with choco topping with caramel topping"<<endl;
    cout<<topping2->getDescription()<<endl;
    cout<<topping2->getCost()<<endl;

}