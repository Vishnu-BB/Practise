#include <iostream>
#include <vector>
using namespace std;

// int main(){
//     int score1;
//     int score2;
//     cout << "Enter number 1: " << endl;
//     cin >> score1;
//     cout << "Enter number 2: "  << endl;
//     cin >> score2;
//     string s;
//     cout << "Enter operator: " << endl;
//     cin >> s;
//     if (s == "+"){
//         int result = score1 + score2;
//         cout << "result: " << result << endl;
//     }
//     else if(s == "-"){
//     int result = score1 - score2;     
//     cout << "result: " << result << endl;  
//     }
//     return 0;
// }

// int main() {
//     int num;
//     cout << "Enter a number: " << endl;
//     cin >> num;
//     if (num < 10 && num > 1){
//         for(int i = 1; i <= num; i++)
//             cout << "*";
//     } else {
//         cout << "Invaild Input";
//     }
//     return 0;
// }

// int main(){
//     const string password = "secret123";
//     cout << "Enter Password: ";
//     string code;

//     while(code != password){
//         cin >> code;
//         if (code != password) 
//             cout << "Incorrect Password. Try again." << endl;
//     }
//     cout << "Login Successful!";
//     return 0;
// }

// int increment_value(int num){
//     num = num + 1;
//     return num;
// }
// void increment_reference(int &num){
//     num = num + 1;
// }
// int main(){
//     int x = 4;
//     increment_value(x);
//     int w = increment_value(x);
//     cout << w << endl;
//     int y = 5;
//     int z = y;
//     increment_reference(y);
//     cout << y;
//     cout << z;
// }

// double calculateAverage(int score1, int score2, int score3){
//     double result = static_cast<double>(score1 + score2 + score3)/3;
//     return result;
// }
// bool isValid(int score){
//     if (score <= 100 && score >= 0){
//         return true;
//     }else{
//         return false;
//     }
// }

// int main(){
//     cout << "enter the test scores" << endl;
//     int s1, s2, s3;
//     cout << "Enter the score1: ";
//     cin >> s1;
//     cout << "Enter the score2:";
//     cin >> s2;
//     cout << "Enter the score3: ";
//     cin >> s3;
//     if (isValid(s1) && isValid(s2) && isValid(s3)){
//         double avg = calculateAverage(s1, s2, s3);
//         cout << avg;
//     }
//     else {
//         cout << "invaild score";
//     }
//     return 0;
// }

// double convertCurrency(double amount, double rate){
//     amount = amount * rate;
//     return amount;
// }
// void applyFee(double &amount, double feePercentage){
//     double fee = amount * feePercentage;
//     amount = amount - fee;
// }
// int main(){
//     double amt = 100;
//     double ex = 0.85;
//     double fee = 0.05;

//     double cur = convertCurrency(amt, ex);
//     applyFee(cur, fee);
//     cout << cur << endl;

// }

// int calculateSum(const vector<int>& numbers){
//     int sum = 0;
//     for (int number : numbers){
//         sum += number;
//     }
//     return sum;
// }
// int main(){
//     vector<int> a = {12, 3, 132, 3};
//     int result = calculateSum(a);
//     cout << result;
//     return 0; 
// }

// bool searchArray(const int arr[], int size, int target){
//     for (int num = 0; num < size; num++){
//         if (arr[num] == target){
//             return true;
//         }
//     }
//     return false;
// }

// int main(){
//     int aa[] = {1,4,65,2};
//     int s = 4;
//     int target = 3;
//     bool a = searchArray(aa, s, target);
//     if (a){
//         cout << "target " << target << " was found!" << endl;
//     }else{
//     cout << "target "<< target << " was not found." << endl;
// } 
// }