// #include <iostream>
// #include <vector>

// std::vector<int> twoSum(std::vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); i++){
//         for (int j = i+1; j < nums.size(); j++){
//             if (nums.at(i) + nums.at(j)){
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }

// int main(){
//     std::vector<int> nums;
//     nums = {2, 7, 8, 20};
//     int target = 9;
//     std::vector<int> ans = twoSum(nums, target);
//     if (!ans.empty()){
//     std::cout<< ans[0] << ',' << ans[1] <<std::endl;
//     }
//     else{
//         std::cout << "no output";
//     }
// }

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// std::vector<int> twoSum(const std::vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if (nums[i] + nums[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }

// int main() {
//     std::vector<int> nums = {2, 7, 8, 20};
//     int target = 9;

//     std::vector<int> ans = twoSum(nums, target);

//     if (!ans.empty()) {
//         std::cout << ans[0] << " " << ans[1] << std::endl;
//     } else {
//         std::cout << "No solution found.\n";
//     }

//     return 0;
// }

// using std::string;

// class Solution {
// public:
//     int idx=0;
//     int strStr(string haystack, string needle) {
//         for(int j = 0; j < needle.length(); j++){
//             for(int i = 0; i < haystack.length(); i++){
//                 if(haystack[i]==needle[j]){
//                     std::cout<<i;
//                 }
//             }
//         }
//         return -1;
//     }
 
// };

// #include <algorithm>

// class Solution {
// public:
//     vector<string> buildArray(vector<int>& target, int n) {
//         vector<string> p;
//         int c = 0;
//         for(int i : target){
//             c = max(i, c);
//         }
//         sort(target.begin(), target.end());
//         for(int i = 0; i < c; i++){
//             p.push_back("push");
//             if((i+1) != target[i]){
//                 cout<<i+1<< "  " <<target[i]<<'\n';
//                 target.insert(target.begin()+i, target[i]);
//                 p.push_back("pop");
//             }
//         }
//         return p;
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         string a = "";
//         int i = 0;
//         int j = s.length();
//         while(i < j){
            
//             a += s[i];
//             i++;
//             j--;
//         }
//         return a;
//     }
// };

// #include <map>

// class Solution {
// public:
//     bool isHappy(int n) {
//         map<int, int> p;
//         while(n != 1 && p.find(n) != p.end()){
//             int a = happy(n);
//             p[n] = a;
//             n = a;
//         }
//         return n == 1;
//     }
//     int happy(int b){
//         int s = 0;
//         while(b>0){
//             int r = b % 10;
//             s += r * r;
//             b /= 10;
//         }
//         return s;
//     }
// };

// int main(){
//     Solution ss;
//     int s = 19;
//     int as = ss.happy(s);
//     cout<<ss.isHappy(as);
//     // for(string i : ss){
//     //     cout<<i<<'\n';
//     // }
//     return 0;
// }
// #include <map>

// class Solution {
// public:
//     bool isHappy(int n) {
//         map<int, int> p ;
//         while(n != 1){
//             if(p.find(n) != p.end()){return false;}
//             int a = sq(n);
//             p[n] = a;
//             n = a;
//         }
//         return n == 1;
//     }
//     int sq(int n){
//         int sum = 0;
//         while(n > 0){
//             int s = n % 10;
//             sum += s*s;
//             n /= 10;
//         }
//         return sum;
//     }
// };
// int main(){
//     Solution ss;
//     int s = 6;
//     cout<<ss.isHappy(s);
// }

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int c;
//         int ma = -2147483648;
//         for(int i = 0; i < nums.size(); i++){
//             ma = max(nums[i], ma);
//         }
//         for(int i = 0; i < nums.size(); i++){
//             if(ma == nums[i]){
//                 return i;
//             }
//         }
//         return 5;
//     }
// };

// int main(){
//     Solution ss;
//     vector<int> s = {-214748364,-2147483647, -21483648};
//     cout<<ss.findPeakElement(s);
// }
// #include <cmath>

// class Solution {
// public:
//     int reverse(int x) {
//         if(x > 1073741824){
//             return 0;
//         }
//         long sum = 0;
//         long b = abs(x);
//         string a = to_string(b);
//         int i = a.length()-1;
        
//         while(b > 0){
//             long r = b % 10;
//             sum += r*(pow(10,i));
//             b /= 10;
//             i--;
//         }
//         if(x < 0){
//             return sum*-1;
//         }
//     return sum;
//     }
// };
// #include <cstdint>

// class Solution {
// public:
//     int reverse(int x) {
//         int sum = 0;
//         int a = abs(x);
//         cout<<a<<'\n';
//         string b = to_string(a);
//         int i = b.length()-1;
//         if(x <= -2147483648 || x >= 2147483647){ return false; }
//         while(a > 0){
//             int r = a % 10;
//             sum += r*(pow(10, i));
//             a /= 10;
//             i--;
//         }
//         if(sum <= -2147483648 || sum >= 2147483647){ return false; }
//         if(x < 0){ return sum*-1; }
//         return sum;
//     }
// };
#include <string>
#include <bits/stdc++.h>

// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         stringstream ss;
//         for(int i:digits){
//             ss<<i;
//         }
//         cout<<ss.str()<<'\n';

//         int z = 0;
//         ss >> z;
//         int b = z + 1;
//         cout<<b<<'\n';
//         string c = to_string(b);
//         cout<<c<<'\n';
//         vector<int> d;
//         for(int i = 0; i < c.length(); i++){
//             d.push_back((c[i])-'0');
//             cout<<d[i]<<'\n';
//         }
//         return d;
//     }
// };
// int main(){
//     Solution ss;
//     vector<int> a = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
//     // vector<int> s = ss.plusOne(a);
//     for(int i:ss.plusOne(a)){
//         cout<<i;
//     }
//     return 0;
// }

// class Solution {
// public:
//     int mySqrt(int x) {
//         int c=0;
//         int p=1;
//         while(x>0){
//             p+=2;
//             c++;
//             x-=p;
//         }
//         return c;
//     }
// };
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int j=nums.size()-1;
//         int c=0;
//         int i=0;
//         while(i<=j){
//             if(nums[j]==val){
//                 j--;
//             }
//             if(nums[i] == val){
//                 int t= nums[i];
//                 nums[i]=nums[j];
//                 nums[j]=t;
//                 c++;
//                 j--;
//             }
//             i++;
//         }
//         for(int i=0;i<=c;i++){
//             nums.pop_back();
//         }
//         for(int i:nums){
//             cout<< i <<'\n';
//         }

//         return nums.size();
//     }
// }

// class Solution {
// public:
//     vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
//     }
// };
// int main(){
//     Solution ss;
//     vector<vector<string>> a = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","12","ALL"}};
//     int val=3;
//     ss.countMentions(val, a);
// }
// #include <algorithm>
// #include <bits/stdc++.h>
// #include<string>
// using namespace std;
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string z = "";
//         int i = a.length()-1;
//         int j = b.length()-1;
//         int sum = 0;
//         int carry=0;
//         while(i >= 0 || j >= 0){
//             sum = carry;
//             carry = 0;
//             // cout<<a[i]<< "  " <<b[j]<<'\n';
//             cout << "sum before addition: " << sum << endl;
//             if(a[i] == '0'){ sum += 0; 
//                 // cout<<sum<<'\n';
//             }
//             else if(a[i] == '1'){sum += 1;}
//             if(b[j] == '0'){ sum += 0; 
//                 // cout<<sum<<'\n';
//             }
//             else if(b[j] == '1'){sum += 1;}
//             if(sum == 2){
//                 carry = 1;
//                 z += '0';
//             }
//             else if(sum > 2){
//                 carry = 1;
//                 z += "1";
//             }else{
//                 z += to_string(sum);
//             }
//             cout << "sum after addition: " << sum << endl;
//             sum =0;
//             i--;
//             j--;
//         }
//         if(carry){z+= "1";}
//         cout<<z<<'\n';
//         int d = 0;
//         int e = z.length()-1;

//         while(d < e){
//             swap(z[d], z[e]);
//             d++;
//             e--;
//         }
//         return (z);
//     }
// };

// int main(){
//     Solution ss;
//     string a = "11001101";
//     string b = "10101";
//     cout<<ss.addBinary(a, b);
// }

// class Solution {
// public:
//     bool isOneBitCharacter(vector<int>& bits) {
//         // reverse(bits.begin(), bits.end());
//         for(int i = 0; i < bits.size(); i++){
//             cout<<bits[i]<<'\n';
//         }
//         int i = 0;
//         int a = bits.size();
//         while(a > 0){
//             if(bits[i] == 1){
//                 cout<<"1 -"<<bits[i]<<'\n';
//                 bits.pop_back();
//                 bits.pop_back();
//                 i++;
//                 a--;
//                 if(bits.empty()){
//                     return false;
//                 }
//             }else{
//                 cout<<bits[i]<<'\n';
//                 bits.pop_back();
//             }
//             i++;
//             a--;
//             if(bits.empty()){
//                     return true;
//                 }
//             // cout<<a<<'\n';
//         }
//     }
// };

// int main(){
//     Solution ss;
//     vector<int> b = {1, 0, 0};
//     cout<<ss.isOneBitCharacter(b);
// }

// class Solution {
// public:
//     vector<string> lengthOfLongestSubstring(string s) {
//     // int lengthOfLongestSubstring(string s) {
//     // string lengthOfLongestSubstring(string s) {
//         string z = "";
//         int c = 0;
//         int ma = -1;
//         int j = 0;
//         vector<string> b;
//         for(int i = 0; i < s.length(); i++){
//             c = 0;
//             while(j < s.length()){
//                 if(z.find(s[j])){
//                     z += s[j];
//                     c++;
//                     // cout<<z<<'\n';
//                 }else{ 
//                     b.push_back(z);
//                     z = "";
                    
//                     // cout<<'y';
//                     break;
//                 }
                
//                 ma = max(ma, c);
//                 j++;
//             }
//             b.push_back(z);
            
//         }
//         return b;
//     }
// };

// int main(){
//     Solution ss;
//     string b = "abcbad";
//     // cout<<ss.lengthOfLongestSubstring(b);
//     vector<string> s = ss.lengthOfLongestSubstring(b);
//     cout<<s.size()<<"\n";
//     for(string i:s){
//         cout<<i<<'\n';
//     }
// }

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    string lengthOfLongestSubstring(string s) {
        string a = "";
        int c = 0;
        int ma = -1;
        for(int i = 0; i < s.length(); i++){
            a = "";
            ma = max(ma, c);
            c = 0;
            for(int j = 0; j < s.length(); j++){
                if(a.find(s[j])){
                    a+=s[j];
                    c++;
                }else{ break; }
            }
        }
        cout<<ma;
        return a;
    }
};

int main(){
    Solution ss;
    string b = "abacabd";
    cout<<ss.lengthOfLongestSubstring(b);
    // vector<string> s = ss.lengthOfLongestSubstring(b);
    // cout<<s.size()<<"\n";
    // for(string i:s){
    //     cout<<i<<'\n';
    // }
}