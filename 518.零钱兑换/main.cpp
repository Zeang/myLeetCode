#include <iostream>
#include <vector>

using namespace std;

// dp[k][i] = dp[k-1][i] + dp[k][i-k]
class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	int N = coins.size();
    	vector<vector<int>> dp(N+1, vector<int>(amount+1, 0));
    	dp[0][0] = 1;
    	for(int i = 1; i <= amount; ++i){
    		dp[0][i] = 0;
    	}
    	for(int j = 1; j < N+1; ++j){
    		for(int i = 0; i < amount+1; ++i){
    			if(coins[j-1] <= i){
    				dp[j][i] = dp[j-1][i] + dp[j][i-coins[j-1]];
    			}else{
    				dp[j][i] = dp[j-1][i];
    			}
    		}
    	}

    	return dp[N][amount];
    }
};

int main(){
	Solution solution;
	vector<int> v = {2};
	cout << solution.change(3, v) << endl;

	return 0;
}