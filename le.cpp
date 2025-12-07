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


int main(){
    Solution s;
    vector<int> target = {2, 3, 4};
    int c = 4;
    vector<string> ss = s.buildArray(target, c);
    for(string i : ss){
        cout<<i<<'\n';
    }
    return 0;
}