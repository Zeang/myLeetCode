#include <iostream>
#include <string>

using namespace std;

// 双向扫描
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, left = 0, right = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                result = max(result, 2 * right);
            else if(right > left)
                left = right = 0;
        }
        left = right = 0;

        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] == ')')
                ++right;
            else
                ++left;
            if(left == right)
                result = max(result, 2 * left);
            else if(left > right)
                left = right = 0;
        }
        
        return result;
    }
};


int main(){
    Solution soluton;
    string str = ")()())";
    cout << soluton.longestValidParentheses(str) << endl;
}