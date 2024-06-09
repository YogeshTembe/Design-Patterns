#include<iostream>
using namespace std;

//Real world example = logProcessor in our project, there should only one instance of logProcessor.
class singleton{
    private: 
        static singleton* instance;  
        singleton(){
            checkNum=0;
        }
    public:
        int checkNum;
        static singleton* getInstance(){
            if(instance==NULL){
                instance=new singleton();
            }
            return instance;
        }
};

singleton *singleton::instance = nullptr;

int main(){
    singleton* s1=singleton::getInstance();
    cout<<s1->checkNum<<endl;
    s1->checkNum=2;
    singleton* s2=singleton::getInstance();
    cout<<s2->checkNum<<endl;
    return 0;
}


