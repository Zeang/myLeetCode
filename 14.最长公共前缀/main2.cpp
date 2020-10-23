#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        
        if(strs.size() == 0)
            return result;
        else if(strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        int i = 0;
        int last = strs.size()-1;
        while(i < strs[0].size() && i < strs[last].size()){
            if(strs[0][i] != strs[last][i])
            	return result;   
            result += strs[0][i];
            ++i;
        }
        return result;
    }
};

int main(){
	Solution solution;
	vector<string> v = {"flower", "flow", "flight"};
	cout << solution.longestCommonPrefix(v);
}