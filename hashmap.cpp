#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int, int> a = {{2022, 20}, {2023, 30}, {2034, 43}};
    a.insert({2024, 302});
    cout<<"asdfa";

    cout<<a.count(2022);
    cout<<a.size()<<"vish";
    for(auto i : a){
        cout<<i.first<<" "<<i.second<<'\n';
    }
    return 0;
}