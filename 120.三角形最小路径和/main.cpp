#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if(len == 0)
            return 0;
        vector<int> dp(len, 0);
        dp[0] = triangle[0][0];

        for(int i = 1; i < len; ++i){
            dp[i] = dp[i-1] + triangle[i][i];
            for(int j = i-1; j > 0; --j){
            	dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        int minTotal = INT_MAX;
        for(auto& num : dp){
            minTotal = min(minTotal, num);
        }
        return minTotal;
    }
};

int main(){
	vector<vector<int>> nums{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	Solution solution;
	cout << solution.minimumTotal(nums) << endl;
}