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

class Solution {
public:
    int idx=0;
    int strStr(string haystack, string needle) {
        for(int j = 0; j < needle.length(); j++){
            for(int i = 0; i < haystack.length(); i++){
                if(haystack[i]==needle[j]){
                    std::cout<<i;
                }
            }
        }
        return -1;
    }
 
};

int main(){
    Solution s;
    s.strStr("butsaid", "sad");
    return 0;
}