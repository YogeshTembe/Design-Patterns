#include <iostream>
#include <vector>
using namespace std;

class ITodoList{
    public:
    virtual string GetHtml()=0;
};

class Todo:public ITodoList{
    string text;
    public:
    Todo(string s):text(s){}
    string GetHtml() override{
        return this->text;
    }
};

class TodoList:public ITodoList{
    string title;
    vector<ITodoList*>todos;//This is vector of ITodoList* and not ITodoList because ITodoList is interface and cannot be instantiated.
    public:
    TodoList(string t,vector<ITodoList*>todos):title(t),todos(todos){}
    string GetHtml() override{ // This function treats normal object and composite object in same way. This is composite design pattern. This is possible because of ITodoList interface
        string html="<h1>"+this->title+"</h1><ul>";
        for(int i=0;i<todos.size();i++){
            html += "<li>"+todos[i]->GetHtml()+"</li>";
        }
        html += "</ul>";
        return html;
    }
};

int main(){
    Todo t0{"dog walking"};
    Todo t1{"eat food"};
    Todo t2{"swim in ocean"};
    Todo t3{"sleepless night"};
    vector<ITodoList*>vec;
    vec.push_back(&t2);
    vec.push_back(&t3);
    TodoList plan_trip{"plan trip",vec};
    Todo t4{"write essay"};
    Todo t5{"traffic management"};
    vector<ITodoList*>vec2;
    vec2.push_back(&t4);
    vec2.push_back(&t5);
    TodoList court_order{"court_order",vec2};
    vector<ITodoList*>vec3;
    vec3.push_back(&t0);
    vec3.push_back(&t1);
    vec3.push_back(&plan_trip);
    vec3.push_back(&court_order);
    TodoList mainList{"mainList",vec3};
    std::cout<<mainList.GetHtml();
    return 0;
}