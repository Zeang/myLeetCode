#include <iostream>
#include <vector>

using namespace std;

// dp[k][i] = dp[k-1][i] + dp[k][i-k]
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for(int j = 1; j < coins.size()+1; ++j){
            for(int i = 0; i < amount+1; ++i){
                if(coins[j-1] > i) continue;
                dp[i] += dp[i-coins[j-1]];
            }
        }
        
        return dp[amount];
    }
};

int main(){
	Solution solution;
	vector<int> v = {1, 2, 5};
	cout << solution.change(5, v) << endl;

	return 0;
}