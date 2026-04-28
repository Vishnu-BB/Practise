#include <vector>
#include <iostream>

using namespace std; 

// class Module{
// public:
//     virtual ~Module() = default;
//     virtual void operation(){
//         cout<<"Module"<<endl;
//     }
// };

// class DerivedModule : public Module{ // runtime polymorphism 
// public:
//     void operation() override{
//         cout<<"derived"<<endl;
//     }
// };

// class container {
// public:
//     vector<Module*> children_;

//     ~container() {
//         for(Module* child : children_){
//             delete child;
//         }
//         children_.clear();
//     }

//     void addchild(Module* child){
//         children_.push_back(child);
//     }
// };

// int main(){
//     container myContainer;
//     myContainer.addchild(new Module());
//     myContainer.addchild(new DerivedModule());

//     for(Module* child : myContainer.children_){
//         child->operation();
//     }
//     return 0;
// }

class Modular_Hub{
public:
    virtual ~Modular_Hub() = default;

    virtual void run(){
        cout<<"runing Modular_Hub"<<endl;
    }
    virtual void fun(){
        cout<<"fun it man!"<<endl;
    }
};

class LightModule : public Modular_Hub{
public:
    virtual void run() override{
        cout<<"Lights on"<<endl;
    }
    virtual void fun() override{
        cout<<"light also fun it.."<<endl;
    }
    ~LightModule() {
        cout << "LightModule destroyed safely." << endl;
    }
};

class ThermostatModule : public Modular_Hub{
public:
    virtual void run() override{
        cout<<"adj"<<endl;
    }
    virtual void fun() override{
        for(int i = 0; i < 5; i++){
            cout<< "pritn values " << i<<endl;
        }
    }
    ~ThermostatModule() {
        cout << "ThermostatModule destroyed safely." << endl;
    }
};

class Hub : public Modular_Hub{
public:
    vector<Modular_Hub*> children_;

    ~Hub(){
        for(Modular_Hub* i : children_){
            delete i;
        }
        children_.clear();
    }
    void addModule(Modular_Hub* m){
        children_.push_back(m);
    }
    void activateAll(){
        for(Modular_Hub* i : children_){
            i->run();
            i->fun();
            i->~Modular_Hub();
        }
    }
};

int main(){
    Hub myHome;
    myHome.addModule(new LightModule());
    myHome.addModule(new ThermostatModule());
    myHome.addModule(new Modular_Hub());

    myHome.activateAll();

    return 0;
}
