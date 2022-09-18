#include<iostream>
using namespace std;


class product{
    public:
    virtual void operation()=0;
};

class concreteProductA:public product{
    public:
    void operation(){
        cout<<"some operation in productA"<<endl;
    }
};
class concreteProductB:public product{
    public:
    void operation(){
        cout<<"some operation in productB"<<endl;
    }
};

class factory{
    public:
    virtual product* getProduct()=0;
};

class concreteFactory1:public factory{
    public:
    product* getProduct(){
        concreteProductA* prodA=new concreteProductA();
        return prodA;
    }
};

class concreteFactory2:public factory{
    public:
    product* getProduct(){
        concreteProductB* prodB=new concreteProductB();
        return prodB;
    }
};

int main(){
    concreteFactory1 factory1;
    concreteFactory2 factory2;
    product* prodAobj=factory1.getProduct();
    product* prodBobj=factory2.getProduct();
    prodAobj->operation();
    prodBobj->operation();
    return 0;
}

