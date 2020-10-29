#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
    	int result = 0;
        stack<int> leftbra;
        map<int, int> m;

        for(int i = 0; i < s.size(); ++i){
        	if(s[i] == '('){
        		leftbra.push(i);
        	}else if(!leftbra.empty()){
    			int index= leftbra.top();
    			m[i] = i-index+1;
    			auto it = m.find(index-1);
    			if(it != m.end()){
    				m[i] += it->second;
    			}
    			result = max(result, m[i]);
    			leftbra.pop();
        	}
        }

        return result;

    }
};

int main(){
	Solution soluton;
	string str = ")()())";
	cout << soluton.longestValidParentheses(str) << endl;
}