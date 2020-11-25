#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> v(26, 0);
        for(auto a : s)
            ++v[a-'a'];

        string result;
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0; i < 26; ++i){
                if(v[i]-- > 0)
                    result += i+'a';
            }
            string temp;
            for(int i = 25; i >= 0; --i){
                if(v[i]-- > 0){
                    temp += i+'a';
                    flag = true;
                }
            }
            result += temp;
        }
        return result;
    }
};

int main(){
	Solution solution;
	string s = "leetcode";
	cout << solution.sortString(s) << endl;
}