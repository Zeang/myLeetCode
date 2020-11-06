#include <iostream>
#include <vector>

using namespace std;

// 回溯
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int N = s.size();
        vector<int> temp;
        dfs(result, temp, s, 0, 0);
        return result;
    }

    void dfs(vector<string>& result, vector<int>& temp, string& s, int tempNum, int index){
        if(index == s.size()){
            if(temp.size() == 4){
                string strTemp = "";
                for(int i = 0; i < temp.size(); ++i)
                    strTemp += to_string(temp[i]) + ".";
                strTemp.pop_back();
                result.emplace_back(move(strTemp));
            }
            return;
        }
        if(temp.size() > 4)
            return;

        tempNum = 10*tempNum + s[index]-'0';
        if(tempNum >= 0 && tempNum < 256){
            temp.emplace_back(tempNum);
            dfs(result, temp, s, 0, index+1);
            temp.pop_back();
        }
        if(tempNum > 0 && tempNum < 26 && temp.size() != 4)
            dfs(result, temp, s, tempNum, index+1);
    }
};

int main(){
	string s = "101023";
	vector<string> vec;
	Solution solution;
	vec = solution.restoreIpAddresses(s);
	for(auto v : vec)
		cout << v << " ";
}