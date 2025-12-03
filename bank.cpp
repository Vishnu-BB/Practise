#include <iostream>
#include <iomanip>
#include <limits> // Required for std::numeric_limits
#include <ios>     // Required for std::streamsize

using namespace std;

// // Function prototypes
// void balance(double amount);
// double deposit();
// double withdraw(double current_balance);

// int main(){
//     double amount = 0;
//     int choice = 0;

//     do{
//         std::cout << "____________________________\n";
//         std::cout << "enter your choice\n";
//         std::cout << "____________________________\n";
//         std::cout << "1. balance\n";
//         std::cout << "2. deposit\n";
//         std::cout << "3. withdraw\n";
//         std::cout << "4. exit\n";
//         std::cin >> choice;

//         // Handle non-numeric input
//         while(std::cin.fail()){
//             std::cout << "Invalid input. Please enter a number (1-4).\n";
//             std::cin.clear(); // Clear the error flag
//             // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the bad input
//             std::cin >> choice; // Try again
//         }

//         switch(choice){
//             case 1:
//                 balance(amount);
//                 break;
//             case 2:
//                 amount += deposit();
//                 balance(amount);
//                 break;
//             case 3:
//                 amount -= withdraw(amount);
//                 balance(amount);
//                 break;
//             case 4:
//                 std::cout << "Exiting...\n";
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please enter a number from 1 to 4.\n";
//         }
//     } while(choice != 4);

//     return 0;
// }

// void balance(double amount){
//     // Format output to 2 decimal places, like currency
//     std::cout << "balance: $" << std::fixed << std::setprecision(2) << amount << '\n';
// }

// double deposit(){
//     double deposit_amount = 0;
//     std::cout << "enter the amt to deposit: \n";
//     std::cin >> deposit_amount;

//     if(deposit_amount < 0){
//         std::cout << "Deposit amount cannot be negative.\n";
//         return 0;
//     }
//     return deposit_amount;
// }

// double withdraw(double current_balance){
//     double withdraw_amount = 0;
//     std::cout << "enter the amt to withdraw: \n";
//     std::cin >> withdraw_amount;

//     if(withdraw_amount < 0){
//         std::cout << "Withdrawal amount cannot be negative.\n";
//         return 0;
//     }
//     if(withdraw_amount > current_balance){
//         std::cout << "Insufficient funds.\n";
//         return 0;
//     }
//     return withdraw_amount;
// }


// #include <iostream>

// double get_total(double princes[], int size);
// int main(){
//     double princes[] = {12.32, 12.23, 1232.12, 234.123};
//     int size = sizeof(princes)/sizeof(double);
//     double total = get_total(princes, size);
//     std::cout << total;
// }
// double get_total(double princes[], int size){
//     double amt;
//     for(int i = 0; i<size; i++){
//         amt += princes[i];
//     }
//     return amt;
// }

// #include <iostream>

// int searchele(int nuzms[], int size, int target);

// int main(){
//     int nums[] = {1, 2, 3, 4,5,6,7,88,90};
//     int target = 2;
//     int size = sizeof(nums)/sizeof(int);

//     int index = searchele(nums, size, target);
//     if (index != -1){
//         std::cout<<"found";
//     }
//     else{
//         std::cout<<"not found";
//     }
//     return 0;
// }

// int searchele(int nuzms[], int size, int target){
    
//     for (int i = 0; i < size; i++){
//         if(nuzms[i] == target){
//             return i;
//         }
//     }
//     return -1;
// }

// #include <iostream>
// #include <algorithm>


// void bubble(int arr[], int size);

// int main(){
//     int arr[] = {1, 4, 6, 7,8, 12, 2, 3, 5, 9};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     // bubble(arr, size);
//     std::sort(arr, arr+size);
//     for (int ele : arr){
//         std::cout<< ele << " ";
//     }
//     std::cout << std::max(0,2) << std::endl;

// }
// void bubble(int arr[], int size){
//     int temp;
//     for (int i = 0; i < size - 1; i++){
//         for (int j = 0; j < size - i - 1; j++){
//             if(arr[j] > arr[j + 1]){
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// #include <iostream>

// int getDigit(const int number);
// int sumOddDigit(const std::string CardNumber);
// int sumEvenDigit(const std::string CardNumber);

// int main(){

//     std::string CardNumber;
//     int result = 0;

//     std::cout << "entera card number";
//     std::cin>>CardNumber;
//     result = sumEvenDigit(CardNumber) + sumOddDigit(CardNumber);
    
//     if (result%10 == 0){
//         std::cout << CardNumber<<"is vailed";
//     }
//     else{
//         std::cout << CardNumber<<"is not vailed";
//     }
//     return 0;
// }
// int getDigit(const int number){
    
//     return number % 10 + (number/ 10);
// }
// int sumOddDigit(const std::string CardNumber){
//     int sum = 0;
//     for (int i = CardNumber.size()-1; i >=0; i-=2){
//         sum += CardNumber[i]-'0';
//     }
//     return sum;
// }
// int sumEvenDigit(const std::string CardNumber){
//     int sum = 0;
//     for (int i = CardNumber.size()-2; i >=0; i-=2){
//         sum += getDigit((CardNumber[i]-'0')* 2);
//     }
//     return sum;
// }


// #include <iostream>
// #include <ctime>


// void drawBoard(std::string *spaces);
// void playerMove(std::string *spaces, char player);
// void computerMove(std::string *spaces, char computer);
// bool checkWinner(std::string *spaces, char player, char computer);
// bool checkTie(std::string *spaces);

// int main(){

//     std::string spaces[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

//     drawBoard(spaces);
//     char player = 'X';
//     char computer = 'O';
//     bool running = true;

//     while(running){
            
//             playerMove(spaces, player);
//             drawBoard(spaces);
//             if(checkWinner(spaces, player, computer)){
//                 break;
//             }
//             else if(checkTie(spaces)){
//                 break;
//             }
//             computerMove(spaces, computer);
//             drawBoard(spaces);
//             if(checkWinner(spaces, player, computer)){
//                 break;
//             }
//             else if(checkTie(spaces)){
//                 break;
//             }
//     }

//     return 0;
// }

// void drawBoard(std::string *spaces){
// std::cout << "     |" << "     |" << "     " << '\n';
// std::cout << "  " <<spaces[0]<< "  |" <<"  "<<spaces[1]<< "  |" <<"  "<<spaces[2]<<"  "<< '\n';
// std::cout << "_____|" << "_____|" << "_____" << '\n';
// std::cout << "     |" << "     |" << "     " << '\n';
// std::cout << "  " <<spaces[3]<< "  |" <<"  "<<spaces[4]<< "  |" <<"  "<<spaces[5]<<"  "<< '\n';
// std::cout << "_____|" << "_____|" << "_____" << '\n';
// std::cout << "     |" << "     |" << "     " << '\n';
// std::cout << "  " <<spaces[6]<< "  |" <<"  "<<spaces[7]<< "  |" <<"  "<<spaces[8]<<"  "<< '\n';
// std::cout << "     |" << "     |" << "     " << '\n';
// }
// void playerMove(std::string *spaces, char player){
//     int number;
//     do{
//         std::cout << "enter the space no you want to mark P: \n";
//         std::cin >> number;
//         number -=1;
//         if(spaces[number] == " "){
//             spaces[number] = player;
//             break;
//         }
//     }while(number > 0 && number < 8);
// }
// void computerMove(std::string *spaces, char computer){
//     int number;
//     srand(time(0));
//     while(true){
//         std::cout << "enter the space no you want to mark P: \n";
//         number = rand() % 9;
//         if (spaces[number] == " "){
//             spaces[number] = computer;
//             break;
//         }
//     }
// }
// bool checkWinner(std::string *spaces, char player, char computer){
//     if(spaces[0] != " " && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
//         spaces[0] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[3] != " " &&spaces[3] == spaces[4] && spaces[4] == spaces[5]){
//         spaces[3] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[6] != " " && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
//         spaces[6] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[0] != " " && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
//         spaces[0] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[1] != " " && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
//         spaces[1] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[2] != " " && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
//         spaces[2] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[0] != " " && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
//         spaces[0] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else if(spaces[2] != " " && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
//         spaces[2] == "X" ? std::cout<<"You win!" : std::cout<<"You lose!";
//     }
//     else{
//         return false;
//     }
//     return true;
// }
// bool checkTie(std::string *spaces){
//     for (int i = 0; i < 9; i++){
//         if(spaces[i] == " "){
//             return false;
//         }
//     }
//     std::cout<<"it's a tie";
//     return true;
// }

// #include <iostream>

// struct mystruct{
//     int mynu;
//     std::string myname;
// };

// void printstu(mystruct &st);
// void chgnum(mystruct &s, int num);

// int main(){
//     struct mystruct e1;
//     struct mystruct e2;
//     e1.myname = "vishnu";
//     e1.mynu = 234325;

//     e2.myname = "sai";
//     e2.mynu = 235;

//     chgnum(e2, 123);
//     std::cout << &e2 <<'\n';
//     printstu(e2);


//     return 0;
// }  
//     void printstu(mystruct &st){
//         std::cout << &st <<'\n';
//         std::cout << st.myname <<'\n';
//         std::cout << st.mynu <<'\n';
// }
// void chgnum(mystruct &s, int num){
//     s.mynu = num;
// }

// C++ program to illustrate default
// constructor without 'explicit'
// keyword
// #include <iostream>
// using namespace std;

// class Complex {
// private:
//     double real;
//     double imag;

// public:
  
//     // Parameterized constructor
//     explicit Complex(double r = 0.0, 
//             double i = 0.0) : real(r), 
//                               imag(i)
//     {
//     }

//     // A method to compare two 
//     // Complex numbers
//     bool operator == (Complex rhs)
//     {
//         return (real == rhs.real && 
//                 imag == rhs.imag);
//     }
// };

// // Driver Code
// int main()
// {
//     // a Complex object
//     Complex com1(3.0, 0.0);

//     if (com1 == Complex(3.0))
//         cout << "Same";
//     else
//         cout << "Not Same";
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void run(int miles);
// int main(){
//     run(50);
// }
// void run(int miles){
//     if(miles>0){
//         cout<<"miles I am running 50";
//         run(miles-1);
//     }
// }

// #include <iostream>
// using namespace std;

// int fact(int num);
// int main(){
//     cout<<fact(10);
//     return 0;
// }
// int fact(int num){
    
//     if(num > 0){

//         return num * fact(num - 1);
//     }else {
//         return 1;
//     }
// }

// template <typename T, typename U>

// auto maxi(T num2, U num1){
    
//     return (num2 > num1) ? num2 : num1;
// }

// int main(){
//     cout<< maxi(2, '4');
//     return 0;
// }

// #include <iostream>

// enum day {sun, mon, tue, wen, thr, fri, sat};

// int main(){
//     day today = sun;
//     switch (today)
//     {
//     case sun:
//         std::cout<<"sun";
//         break;
    
//     default:
//         std::cout << "day";
//         break;
//     }
// }

// class empl{
// public:
//         double salary = 50000;
//         int work_hours = 11;

    
//         std::string name;
//         int num;
//         int exp;

        
    
//     // empl(std::string name, int num, int exp){
//     //     this->name = name;
//     //     this->num = num;
//     //     this->exp = exp;
//     // }


//     double getsal(){
//         return salary;
//     }
//     int getwk(){
//         return work_hours;
//     }
//     void setsal(double salary){
//         this->salary = salary;
//     }
//     void setwk(int work_hours){
//         this->work_hours = work_hours;
//     }
//     void eat(){
//         cout<<" denge eating"<<'\n';
//     }
//     void sleep(){
//         cout<<"ununug"<<'\n';
//     }
//     void masterba(){
//         cout<<"doing"<<'\n';
//     }
// };

// class evo : public empl{
//     evo(){
//         this->name = name;
//         this->num = num;
//     }
// };

// int main(){
    
//     empl e1;
//     e1.name = "vishnu";
//     evo ev();
//     e1.name = "vas";
//     e1.eat();
//     cout<<e1.name<<'\n';
//     cout<<e1.num<<'\n';
//     cout<<e1.exp<<'\n';
//     cout<<e1.getsal()<<'\n'; 
//     e1.setsal(45000);
//     cout<<e1.getsal()<<'\n';
//     cout<<e1.getwk()<<'\n';
//     e1.setsal(600000);
//     e1.setwk(5);
//     cout<<e1.getsal()<<'\n'; 

//     // e1.masterba();
//     // e1.eat();

// }

class shape{
    public:
        double area;
        double voulume;
    
};
class cude : public shape{
    public:
        int side;

    cude(int side){
        this->side = side;
        this->area = side * side * 6;
        this->voulume = side * side * side; 
    }
};
class sphere : public shape{
    public:
        int radius;
    
    sphere(int radius){
        this->radius = radius;
        this->area = 4 * 3.14 * radius * radius;
        this->voulume = (4/3.0) * 3.14 * (radius * radius * radius);
    }
};

int main(){
    sphere sh(5);
    cude cu(4);
    cout<<sh.area<< "   ";
    cout<<cu.voulume;
    return 0;
}