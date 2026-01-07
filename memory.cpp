#include <iostream>

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


#include <unistd.h>
#include <stdlib.h>

int main(){
    void *p1 = malloc(1024*1024*10);
    sleep(5);
    free(p1);
    sleep(5);
}