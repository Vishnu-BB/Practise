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

using namespace std;

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

// int main(){
//     Solution s;
//     s.strStr("butsaid", "sad");
//     return 0;
// }
#include <algorithm>
// class Solution {
// public:
    

//     int singleNumber(vector<int>& nums) {
//         size_t s = nums.size();
//         // for (int i = 0; i<s; i++){
//         //     cout<<nums[i]<<"\n";
//         // }
//         cout<<'\n';
//         sort(nums.begin(), nums.end());
//         int c = 0;
//         for (int i = 0; i<s; i++){
//             c = c ^ nums[i];
//             // cout<<nums[i]<<"\n";
//         }

//         return c;
        
//     }
// };

// int main(){
//     Solution ss;
//     vector<int> nums = {3, 4, 4, 6, 7 ,7, 3};
//     cout<<ss.singleNumber(nums);

//     return 0;
// }

// #include <iomanip>

// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> d;
//         for(int i = 0; i < nums.size(); i++){
//             int c = 0;
//             for(int j = 0; j < nums.size(); j++){
//                 if(nums[j] < nums[i]){
//                     c++;
//                 }  
//             } 
//             d.push_back(c); 
//         }
//         return d;
//     }
// };
#include <set>
#include <map>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> fre;
        vector<int> d;
        for(int n: nums){
            fre[n]+=1;
        }
        for(int i = 1; i<nums.size(); i++){
            // if(fre.find(i) == fre.end()){
            //     d.push_back(i);
            // }
        }
        return d;
    }
};

int main(){
    Solution ss;
    vector<int> s = {1,1};
    vector<int> sa = ss.findDisappearedNumbers(s);
    for(int i = 0; i < s.size(); i++){
        cout<<sa[i];
    }
    
    return 0;
}