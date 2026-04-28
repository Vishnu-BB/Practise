#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

// class order{
//     int qty;
//     int price;
// };
// class m_memory{
//     int no_of_obj;
//     int size;
//     char* memory;
//     vector<void*> pool;
// };

class MemoryManager{
    vector<void*> freeList_;
    char* memory_;
public:
    MemoryManager(const uint32_t objSize,const uint32_t noOfObj){
        memory_ = new char[objSize*noOfObj];
        for(auto it = 0; it < noOfObj; it++){
            freeList_.push_back(memory_ + it*objSize);
        }
    }
    ~MemoryManager(){
        delete[] memory_;
    }
    void* allocateMemory(){
        void* memoryChunk = freeList_.back();
        freeList_.pop_back();
        return memoryChunk;
    }
    void deallocateMemory(void* memoryAddress){
        freeList_.push_back(memoryAddress);
    }
};


class order1{
    int qty;
    public:
        order1(int qty) : qty(qty){}

    void logOrder() const{
        cout<<"object address: "<<this << "qty" << qty << endl;
    }
    void* operator new(const size_t size){
        return memoryMemory.allocateMemory();
    }
    void operator delete(void* memoryAdress){
        return memoryMemory.deallocateMemory(memoryAdress);
    }
    static MemoryManager memoryMemory;
};
MemoryManager order1::memoryMemory(sizeof(order1), 10);
 
class order{
    int qty;
    public:
        order(int qty) : qty(qty){}

    void logOrder() const{
        cout<<"object address: "<<this << "qty" << qty << endl;
    }
};

int main(){

    auto starttime1 = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch()).count();

    for(int i = 0; i < 9999; i++){
        order1* obj1 = new order1(i+100);
        order1* obj9 = new order1(i+100);
        order1* obj8 = new order1(i+100);
        order1* obj7 = new order1(i+100);
        order1* obj6 = new order1(i+100);
        order1* obj5 = new order1(i+100);
        order1* obj4 = new order1(i+100);
        order1* obj3 = new order1(i+100);
        order1* obj2 = new order1(i+100);
        
        delete obj1;
        delete obj2;
        delete obj3;
        delete obj4;
        delete obj5;
        delete obj6;
        delete obj7;
        delete obj8;
        delete obj9;
    }       
    auto endtime1 = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch()).count();
    
    // auto diff = chrono::duration_cast<chrono::nanoseconds>(endtime-starttime);
        cout << "0  - "<<(endtime1 - starttime1) << "ns" <<endl;
        auto starttime = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch()).count();

    for(int i = 0; i < 9999; i++){
        order* obj1 = new order(i+100);
        order* obj9 = new order(i+100);
        order* obj8 = new order(i+100);
        order* obj7 = new order(i+100);
        order* obj6 = new order(i+100);
        order* obj5 = new order(i+100);
        order* obj4 = new order(i+100);
        order* obj3 = new order(i+100);
        order* obj2 = new order(i+100);
        
        delete obj1;
        delete obj2;
        delete obj3;
        delete obj4;
        delete obj5;
        delete obj6;
        delete obj7;
        delete obj8;
        delete obj9;
    }       
    auto endtime = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch()).count();
    
    // auto diff = chrono::duration_cast<chrono::nanoseconds>(endtime-starttime);
        cout << "1  - "<<(endtime - starttime) << "ns" <<endl;

    return 0;
}