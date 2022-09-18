#include<iostream>
using namespace std;

class Ireceiver{
    public:
        virtual void turnOn()=0;
        virtual void turnOff()=0;
};

class LightBulbReceiver:public Ireceiver{
    public:
        void turnOn(){
            cout<<"Turned On light"<<endl;
        }
        void turnOff(){
            cout<<"Turned off light"<<endl;
        }
};

class Icommand{   
    public:
        Ireceiver* r;
        Icommand(Ireceiver* re){r=re;}
        virtual void execute()=0;
        virtual void unexecute()=0;
};

class turnOnDeviceCommand:public Icommand{
    public:
        turnOnDeviceCommand(Ireceiver* r):Icommand(r){}
        void execute(){
            r->turnOn();
        }
        void unexecute(){
            r->turnOff();
        }
};

class turnOffDeviceCommand:public Icommand{
    public:
        turnOffDeviceCommand(Ireceiver* r):Icommand(r){}
        void execute(){
            r->turnOff();
        }
        void unexecute(){
            r->turnOn();
        }
};

class invoker{
    public:
        Icommand* button1;
        Icommand* button2;
        invoker(Icommand* button1_given, Icommand* button2_given){
            button1=button1_given;
            button2=button2_given;
        }
        void clickButton1(){
            button1->execute();
        }
        void clickButton2(){
            button2->execute();
        } 
};

int main(){
    LightBulbReceiver* philipsBulb=new LightBulbReceiver();
    turnOnDeviceCommand* OnCommand=new turnOnDeviceCommand(philipsBulb);
    turnOffDeviceCommand* OffCommand=new turnOffDeviceCommand(philipsBulb);
    invoker BulbRemoteController=invoker(OnCommand,OffCommand);
    BulbRemoteController.clickButton1();
    BulbRemoteController.clickButton2();
    return 0;
}
