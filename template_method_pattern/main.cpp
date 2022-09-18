#include<iostream>
using namespace std;

//abstract class record
class Record{
    public:
        //this is template method
        //this method defines the template to user the other methods in the particular place and in particular order
        void save(){
            beforeSave();
            cout<<"save record to db\n";
            afterSave();
        }
        virtual void beforeSave()=0;
        virtual void afterSave()=0;
};

class User:public Record{
    public:
        void beforeSave(){
            cout<<"before saving validate the user record\n";
        }
        void afterSave(){
            cout<<"after saving notify the user\n";
        }
};

int main(){
    User* john=new User();
    john->save();
    return 0;
}

