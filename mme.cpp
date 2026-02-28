// #include <iostream>
// #include <memory>
// int main(){
//     int* ptr;
//     ptr = new int(10);
//     std::cout<<*ptr<<std::endl;
//     *ptr = 20;
//     std::cout<<*ptr<<std::endl;
//     delete ptr;
//     ptr = nullptr;
//     return 0;
// }

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    set<int> ii;
    set<int> jj;
    void setZeroes(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) {
                    ii.insert(i);
                    jj.insert(j);
                }
            }
        }
        for(auto st:ii){
            for(int j = 0; j < matrix.size(); j++){
                matrix[st][j]=0;
            }
        }
        for(auto st:jj){
            for(int j = 0; j < matrix.size(); j++){
                matrix[j][st]=0;
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
        for(int i : ii){
            cout<<i<<" "<<endl;
        }
        for(int i : jj){
            cout<<i<<" ";
        }
    }
};

int main(){
    Solution ss;
    vector<vector<int>> s = {{0, 1}};
    ss.setZeroes(s);
    return 0;
}