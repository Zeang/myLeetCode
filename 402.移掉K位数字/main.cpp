#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> v;
        for(int i = 0; i < num.size()-1; ++i){
            v.emplace_back(num[i]);
            if(num[i] > num[i+1]){
                while(k > 0 && !v.empty() && v.back() > num[i+1]){
                    v.pop_back(), --k;
                }
            }
        }
        v.emplace_back(num.back());
        while(k--){
            v.pop_back();
        }
        string result = "";
        bool flag = true;
        for(auto a : v){
            if(flag){
                if(a == '0')
                    continue;
                else
                    flag = false;
            }
            result += a;
        }
        return result.size() == 0 ? "0" : result;
    }
};

int main(){
	Solution solution;
	string num = "1432219";
	cout << solution.removeKdigits(num, 3) << endl;
	return 0;
}