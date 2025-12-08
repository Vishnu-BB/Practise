#include <stack>
#include <iostream>
using namespace std;

// int main(){
//     stack<int> s;
//     s.push(12);
//     s.push(10);
//     s.push(8);
//     s.push(6);
//     s.push(4);
//     cout<<s.size()<<'\n';
//     stack<int> st(s);

//     while(!st.empty()){
//         cout<<st.top()<<'\n';
//         st.pop();
//     }
//     cout<<bool(st.empty());
//     return 0;
// }

class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                p.push(s[i]);
                cout<<p.top()<<'\n';
            }else{
                if(p.empty() == 1){
                    return true;
                }
                else if(s[i] == ')' && p.top() == '('){
                    cout<<s[i]<<'\n';
                    p.pop();
                }else if(s[i] == '}' && p.top() == '{'){
                    cout<<s[i]<<'\n';
                    p.pop();
                }else if(s[i] == ']' && p.top() == '['){
                    cout<<s[i]<<'\n';
                    p.pop();
                    // cout<<p.top()<<'\n';
                }
            }
        }
        return true;
    }
};

int main(){
    Solution ss;
    string s = "()[]}";
    cout<<ss.isValid(s);
    return 0;
}