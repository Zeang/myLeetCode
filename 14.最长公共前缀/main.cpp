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
        for(int j = 0; j < strs[0].size(); ++j){
            for(int i = 1; i < strs.size(); ++i){
                if(j >= strs[i].size() || strs[0][j] != strs[i][j])
                    return result;
            }
            result += strs[0][j];
        }

        return result;
    }
};

int main(){
	Solution solution;
	vector<string> v = {"flower", "flow", "flight"};
	cout << solution.longestCommonPrefix(v);
}