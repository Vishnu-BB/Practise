// Level 1: Easy (Conceptual)
// Where is memory stored? If you declare int a = 10; inside a function, is it stored on the Stack or the Heap?
// stack
// The new operator: What does the new operator return? (e.g., a value, a reference, or a pointer?)
// pointer
// Memory Leaks: What is a "Memory Leak" in C++?
// we allocate the memory and forget to delete the memory the memory leak happens.
// correct me if I am wrong.

// Level 2: Medium (Code Analysis)
// Find the Bug: What is wrong with the following code snippet?

void process() {
//     int* data = new int[100];
        int* data = new int(100);
//     // ... some processing ...
    delete data;
}
// in new int[100]; is wrong it suppose to be like new int(100);

// Dangling Pointers: In the code below, what is the state of ptr after the delete call?

// int* ptr = new int(5);
// delete ptr;
// // What is ptr now?
// Scope vs. Lifetime: Will the memory allocated here be freed automatically when the function ends? Why or why not?
// the memory allocaated here is freed but the ptr is still there we need to point to nullptr otherwise it will case the dangling pointers
void create() {
    double* val = new double(3.14);
    delete val;
}
// we allocated the memory in heap for val with double size(32 bits) but not deleted the val not we can access it the lifetime is infinty untill we delete it.

// Level 3: Hard (Application & Logic)
// The Double Free: What happens if you call delete on the same pointer twice?
// free(): double freee detected in tcache2
// Array Allocation Logic: Write a small C++ function that:

// Takes an integer n as an argument.
// Allocates an array of n integers on the heap.
// Fills it with zeros.
// Returns the pointer to the array. (Don't forget to mention how the caller should eventually free this memory!)
// Pointer Reassignment: What happens to the first int allocated in this snippet?
// the p is 20 now.
#include <iostream>
// int main(){
// int* p = new int(10);
// p = new int(20);
// std::cout<<*p<<std::endl;
// delete p;
// return 0;
// }

// Q8 (Array Allocation Logic): Incomplete.

// You didn't write the specific function requested, but you demonstrated new and delete in 
// main
// .
// Challenge: Can you write a function int* createArray(int n) that returns a heap-allocated array of size n filled with zeros?
#include <memory>

int* createArray(int a){
    std::shared_ptr<int> ar =  std::make_shared<int>(a);
    {
        std::shared_ptr<int> p1 = ar;
        std::cout<<p1<<std::endl;
    }
    return 0;
}

int main(){
    int a;
    std::cin>>a;
    int* (*functionptr)(int)=createArray;
    functionptr(a);
    return 0;
}
