#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
// void fun(std::string name, int age);

// double square(int a);
// double cube(int a);
// std::string name = "Ankanna";
// void hi();
// void hi(std::string name);
// void swap(std::string &x, std::string &y);

int main() {
  // std::cout<<"changa\n"
  //             <<"pust name" << std::endl;
  // std::string first_name;
  // std::cin>>first_name;
  // std::cout<<first_name<<std::endl;
  // int no_of_stepsk;
  // no_of_stepsk = -1; /// don't know the int
  // // float ni = 333.2;
  // double no = 23.3241341;
  // // char dec_poi = '.';
  // std::string name = "???"; /// don't know the name
  // // bool toa_on = true;
  // std::cin>>name>>no_of_stepsk;
  // std::cout<<name<<no_of_stepsk<<std::endl;

  // std::cout << "Size of char: " << sizeof(char) << " byte(s)" << std::endl;
  // std::cout << "Size of int: " << sizeof(int) << " byte(s)" << std::endl;
  // std::cout << "Size of float: " << sizeof(float) << " byte(s)" << std::endl;
  // std::cout << "Size of double: " << sizeof(double) << " byte(s)" <<
  // std::endl; std::cout << "Size of bool: " << sizeof(bool) << " byte(s)" <<
  // std::endl;

  // std::string name;
  // name = "vishnu";
  // std::cout<<name+ ".jr"<<std::endl;
  // int age = 20;
  // age += 2;
  // std::cout << age<<std::endl;

  // std::cout<< "enter no: "<< std::endl;
  // int no;
  // std::cin>>no;
  // std::cout<< "n" << no
  // <<"n*n"<< no*no<< "n twice" << 2*no << no/2 << no * 0.5 << sqrt(no) <<
  // std::endl;

  // std::string first_name, second_name;
  // std::cout << "enter fn and sn";
  // std::cin >> first_name
  //         >> second_name;
  // std::cout<< first_name +' '+ second_name << std::endl;

  // std::string current;
  // std::string previous;

  // int no = 0;
  // while (std::cin >> current){
  //     if (previous == current)
  //         std::cout<< "repeated" << std::endl;
  //     std::cout << no << std::endl;
  //     previous = current;
  //     no++;
  // }

  // int string = 7;
  // std::cout<<string<<std::endl;

  // char c = 'x';
  // int i = c;
  // int ii = c + 1000;
  // double d = ii + 2.34;
  // char y = d;
  // int x = y;
  // std::cout<<y<<' '<<x<<std::endl;
  // std::cout<<c<<' '<<i<<' '<<ii<<' '<<d<<std::endl;

  // double d = 0;
  // while (std::cin>>d){
  //     int i = d;
  //     char c = i;
  //     std::cout << "d == " << d << ' '
  //     << "i == " << i << ' '
  //     << "c == " << c << ' '
  //     << "char("<<c<<")\n";
  // }

  // int x1 = 2.34;
  // int x2 {23.3};   //error
  // int x4 = {43.2}; //error
  // int x6(3.4);
  // std::cout<<x1<<' '<<' '<<' '<<x6;

  // int x = 5;
  // double d = 2.2;
  // std::vector<int> v = {1, 3, 4, 5, 6, 7, 9};
  // std::vector<double> vv = {2.33, 4.323, 2.123, 22.123, 4.323};
  // std::pair<std::string,int> p {"hear",17};
  // for (int x : v) std::cout<<x<< " ";
  // std::cout<<std::endl;

  // double a, b;
  // std::cin >> a;
  // std::cin>> b;
  // double aa = pow(a, 2);
  // double bb = pow(b, 2);
  // std::cout << aa << bb;
  // double c = sqrt(aa + bb);
  // std::cout << c;

  // int month;
  // std::cout<<"enter monthe";
  // std::cin>>month;
  // switch (month)
  // {
  // case 1:
  //     std::cout<<"monday";
  //     break;
  // case 2:
  //     std::cout<<"tuesday";
  //     break;
  // default:
  //     break;
  // }

  // char grade;
  // std::cout<<"enter grade";
  // std::cin>>grade;
  // switch (grade)
  // {
  // case 'A':
  //     std::cout<< "good raa";
  //     break;
  // case 'B':
  //     std::cout<< "nice raa";
  // case 'C':
  //     std::cout<< "okkk raa";
  // default:
  //     std::cout<< "antha assam";
  //     break;
  // }

  // std::string name;
  // std::getline(std::cin, name);
  // (name.length() > 12) ? std::cout<< "too long" : std::cout<<"okk";

  // srand(time(0));
  // int nums = rand() % 6 + 1;
  // std::cout<<nums;

  // int guess;
  // std::cout<<"guess a number b/w 1 to 100" << std::endl;
  // srand(time(0));
  // int num = rand() % 100 + 1;
  // do{
  //     std::cin>>guess;
  //     std::cout<<num;
  // }while(guess != num);

  // std::string name;
  // int age;

  // std::cout<<"enter name and age";
  // std::getline(std::cin, name);
  // std::cin>>age;
  // fun(name, age);

  // std::cout<<square(5)<<std::endl;
  // std::cout<<cube(5);

  // std::string name = "vishnu";
  // hi();
  // hi(name);
  // std::cout<< ::name<<'\n';

  //     const int SIZE = 99;
  //     std::string foods[SIZE];
  // int x = 0;
  // int y = 0;
  // int z = 0;
  //     fill(foods, foods + (SIZE/3), "MUDDA");
  //     fill(foods+(SIZE/3), foods + (SIZE/3)*2, "pogal");
  //     fill(foods+(SIZE/3)*2, foods+SIZE, "RAGI DOSA");
  //     for(std::string food: foods){
  //         std::cout << food << '\n';
  //         if(food == "MUDDA"){

  //             x+=1;
  //             std::cout << x ;
  //         }else if(food == "pogal"){

  //             y+=1;
  //             std::cout << y;
  //         }else{

  //             z+=1;
  //             std::cout << z;
  //         }
  //     }

  // std::string foods[3];
  // int size = sizeof(foods)/sizeof(std::string);
  // std::string temp;

  // for(int i = 0; i < size; i++){
  //     std::cout << "enter the fav food or quit:";
  //     std::getline(std::cin, temp);
  //     if (temp == "q"){
  //         break;
  //     }else{
  //         foods[i] = temp;
  //     }
  // }
  // std::cout << "your fav food:";
  // for (int i = 0; !foods[i].empty(); i++){
  //     std::cout<<foods[i]<<'\n';
  // }

  // std::string cards[][3] = {{"mustang", "escape", "f-150"},
  //                             {"corvette", "equinox", "silverado"},
  //                         { "challenger", "durango", "ram 1500"}};

  // int rows = sizeof(cards)/sizeof(cards[0]);
  // int cols = sizeof(cards[0])/sizeof(cards[0][0]);

  // for (int i = 0 ; i < rows; i++){
  //     for (int j = 0; j < cols; j++){
  //         std::cout<< cards[i][j]<<" ";
  //     }
  //     std::cout << '\n';
  // }

  // std::string question[] = {"who are lyou?",
  // "what are lyou doning",
  // "what you like to do?"};
  // std::string options[][4] = {{"a. vishnu", "b. sai", "c. ankanna", "d.
  // kurra"},
  //                             {"a. fun", "b. playing", "c. learning", "d.
  //                             nothing"},
  //                             {"a. swim","b. run", "c. read", "d. talk"}};
  // char answer[] = {'a', 'd', 'b'};

  // for (int i = 0; i < sizeof(question)/sizeof(std::string); i++){
  //     std::cout<<question[i]<<std::endl;
  //     for (int j = 0; j < sizeof(options)/sizeof(std::string); j++){
  //         std::cout<<options[i][j];
  //     }
  // }

  // std::vector<int> nums = {1, 3, 41, 55,6,14 };
  // int size = sizeof(nums)/sizeof(int);

  // std::cout << size;

  // std::vector<int> result;
  // result = {1, 3, 4, 5, 23, 43,35,3};
  // std::sort(result.begin(), result.end());
  // for(auto results: result)
  // std::cout << results << " ";

  // std::vector<int>res = {-4, -1, -1, 0, 1, 2};
  // std::vector<std::vector<int>> result;
  // for (int i = 0; i < res.size(); i++){
  //     if(i > 0 && res[i] == res[i - 1]){
  //         // std::cout << res[i] << res[i-1] << "\n";
  //         continue;
  //     }
  //     for(int j = i+1; j < res.size(); j++){
  //         std::vector<int> pair = {res[i], res[j], res[i+1]};
  //         // You might want to add a third element or some logic here
  //         result.push_back(pair);
  //     }
  // }
  // // Print the result to see the output
  // for (const auto& triplet : result) {
  //     for (int num : triplet) {
  //         std::cout << num << " ";
  //     }
  //     std::cout << std::endl;
  // }

  // std::string x = "kko";
  // std::string y = " water";

  // swap(x, y);

  // std::cout<< " "<< &x << "\n " << &y ;

  // std::string name = "vishnu";
  // int age = 22;

  // std::string *pname = &name;
  // int *page = &age;

  // std::cout<<&name<< " " << pname;

  // char *pgrades;
  // int size;
  // std::cout << "enter the size of the grades";
  // std::cin >> size;

  // pgrades = new char[size];

  // for (int i = 0; i < size; i++) {
  //   std::cout << "enter the grade#" << i + 1;
  //   std::cin >> pgrades[i];
  // }
  // for (int i = 0; i < size; i++) {
  //   std::cout << pgrades[i];
  // }
  +
  
 

  return 0;
}
// void swap (std::string &x, std::string &y){
//     std::string temp;
//         temp = x;
//         x = y;
//         y = temp;

//         std::cout<< " "<< &x << "\n " << &y ;
// }
// void hi(){
//     std::cout<<"hi"<<'\n';
// }
// void hi(std::string name){
//     std::cout<<"hi" << ::name<<'\n';
// }
// double square(int a){
//     double result = a * a;
//     return result;
// }
// double cube(int a){
//     double result = a * a * a;
//     return result;
// }
// void fun(std::string name, int age){

//     if (age>=21){
//         std::cout<<"congrats!" << name << "on your "<< age << "th bd";
//     }
//     else if(age == 0){
//         std::cout<<"you not yet born man";
//     }
//     else{
//         std::cout<<"wait " << name<< " for" << 21 - age << "years";
//     }
// }
