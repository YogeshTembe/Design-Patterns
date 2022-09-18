#include <iostream>
using namespace std;

class IFlyBehaviour{
    public:
        virtual void fly()=0;
};

class noFly:public IFlyBehaviour{
    public:
        void fly(){
            cout<<"I dont fly\n";
        }
};

class jetFly:public IFlyBehaviour{
    public:
        void fly(){
            cout<<"I jet fly\n";
        }
};

class simpleFly:public IFlyBehaviour{
    public:
    void fly(){
        cout<<"I simply fly\n";
    }
};

class IQuackBehaviour{
    public:
        virtual void quack()=0;
};

class noQuack:public IQuackBehaviour{
    public:
        void quack(){
            cout<<"I dont quack\n";
        }
};

class simpleQuack:public IQuackBehaviour{
    public:
        void quack(){
            cout<<"I simply quack\n";
        }
};

class IDisplayBehaviour{
    public:
        virtual void display()=0;
};

class simpleDisplay:public IDisplayBehaviour{
    public:
        void display(){
            cout<<"I display simply\n";
        }
};

class Duck{
    private:
        IFlyBehaviour *fb_;
        IQuackBehaviour *qb_;
        IDisplayBehaviour *db_;
    public:
        Duck(IFlyBehaviour *fb, IQuackBehaviour *qb, IDisplayBehaviour *db){
            fb_=fb;
            qb_=qb;
            db_=db;
        }

        void fly(){
            fb_->fly();
        }

        void quack(){
            qb_->quack();
        }

        void display(){
            db_->display();
        }    
};

class rubberDuck:public Duck{
    public:
        noFly flyBehaviour;
        noQuack quackBehaviour;
        simpleDisplay displayBehaviour;
        rubberDuck():Duck(&flyBehaviour,&quackBehaviour,&displayBehaviour){
        }
};

class mountainDuck:public Duck{
    public:
        jetFly flyBehaviour;
        simpleQuack quackBehaviour;
        simpleDisplay displayBehaviour;
        mountainDuck():Duck(&flyBehaviour,&quackBehaviour,&displayBehaviour){}
};
int main(){
    rubberDuck john;
    john.fly();
    john.quack();
    john.display();

    mountainDuck robby;
    robby.fly();
    robby.quack();
    robby.display();

}