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
class Solution {
public:
    bool isHappy(int n) {
        
        while((n*n) > 10){
            int s = 0;
            int sum = 0;
            
            s = n % 10;
            cout<<s<<'\n';
            sum += s*s;
            
            // cout<<n<<'\n';
            // cout<<sum<<'\n';
        }
        if(n == 1){
            return true;
        }//else{
        //     return false;
        // }
        return false;
    }
};

int main(){
    Solution ss;
    int s = 19;
    cout<<ss.isHappy(s);
    // for(string i : ss){
    //     cout<<i<<'\n';
    // }
    return 0;
}

class Solution {
public:
    int isHappy(int n) {
       int s = 0;
       int sum = 0;
    for(int i = 0; i < 2; i++){
        s = n % 10;
        // cout<<s<<'\n';
        sum += s*s;
        cout<<s<<'\n';
        n = n / 10;
        
    }
        return sum;
    }
};

int main(){
    Solution ss;
    int s = 19;
    cout<<ss.isHappy(s);
}