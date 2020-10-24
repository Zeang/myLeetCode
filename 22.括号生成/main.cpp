#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        Recursion(n, 0, 0, result, temp);
        return result;
    }

    void Recursion(int n, int left, int right, vector<string>& result, string& temp){
    	if(n == right){
    		result.emplace_back(temp);
    		return;
    	}
    	if(left < n){
    		temp.push_back('(');
    		Recursion(n, left+1, right, result, temp);
    		temp.pop_back();
    	}
    	if(right < left){
    		temp.push_back(')');
    		Recursion(n, left, right+1, result, temp);
    		temp.pop_back();
    	}
    }
};

int main()
{
	Solution solution;
	vector<string> result = solution.generateParenthesis(3);
	for(auto& r: result){
		cout << r << endl;
	}
}