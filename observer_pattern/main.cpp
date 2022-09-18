#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class IObserver{
    public:
        virtual void update(int,int)=0;
};

class IObservable{
    public:
        virtual void add(IObserver*)=0;
        virtual void remove(IObserver*)=0;
        virtual void notify()=0;

};

class weatherStation:public IObservable{
    private:
        int temperatureReading_;
        int humidityReading_;
        vector<IObserver*> observers;
    public:
        weatherStation(){
            temperatureReading_=20;
            humidityReading_=40;
        }
        void add(IObserver* observer){
            observers.push_back(observer);
        }
        void remove(IObserver* observer){
            std::vector<IObserver*>::iterator position=std::find(observers.begin(),observers.end(),observer);
            if(position!=observers.end()){
                observers.erase(position);
            }
        }
        void notify(){
            for(int i=0;i<observers.size();i++){
                observers[i]->update(temperatureReading_,humidityReading_);
            }
        }
};

class ScientistA:public IObserver{
    public:
        ScientistA(IObservable* observable){
            observable->add(this);
        }
        void update(int temperatureReading,int humidityReading){
            cout<<"ScientistA update method-"<<temperatureReading<<","<<humidityReading<<endl;
        }
};

class ScientistB:public IObserver{
    public:
        ScientistB(IObservable* observable){
            observable->add(this);
        }
        void update(int temperatureReading,int humidityReading){
            cout<<"ScientistB update method-"<<temperatureReading<<","<<humidityReading<<endl;
        }
};

int main(){
    weatherStation texasLab;
    ScientistA martin(&texasLab);
    ScientistB stella(&texasLab);
    texasLab.notify();
    return 0;
}
