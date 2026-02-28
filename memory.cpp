#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// int main(){
//     while (true)
//     {
//         int *p = new int[1000];
//         cout<<"w"<<endl;

//         delete []p;
//         cout<<"freed"<<endl;
//     }

//     return 0;
// }
// void crash()
// {
//     int arr[1000000];
//     crash();
// }

// int main(){
//     int *p = new int(50);
//     delete p;
//     p = nullptr;
//     // crash();
//     // cout<<*p<<endl;
//     // int *p = new int[10];
//     // p[100] = 50;   // writing outside heap block → memory corruption

//     return 0;
// }


// #include <unistd.h>
// #include <stdlib.h>

// int main(){
//     void *p1 = malloc(1024*1024*10);
//     sleep(5);
//     free(p1);
//     sleep(5);
// }

// int main(){
//     int *num = new int(100);
//     vector<int> *v = new vector<int>({2,3,5,6,7});
    
//     for(auto i : *v){
//         cout<<i<<endl;
//     }

//     cout<<num<<endl;
//     delete num;
//     delete v;
// }

#include <iostream>
#include <memory>

int main(){
    // int value = 100;
    // int* ptr = &value;

    // std::cout << *ptr << std::endl;

    // int num = 50;
    // int* num_ptr = &num;
    // int** num_ptr_ptr = &num_ptr;

    // num = 99;
    // std::cout<<**num_ptr_ptr<<std::endl;
    int* ptr;
    ptr = new int(10);
    std::cout<<*ptr<<std::endl;
    *ptr = 20;
    std::cout<<ptr<<std::endl;
    std::cout<<"vsihnu"<<std::endl;
    delete ptr;
    ptr = nullptr;
    
    return 0;
    
}