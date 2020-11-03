#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {;
    	int N = nums.size();
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;
        int numMax = 0;
        for(int i = 0; i < N; ++i){
        	if(numMax >= i + nums[i]){
        		continue;
        	}else{
        		numMax = i + nums[i];
        	}
        	for(int j = 1; j <= nums[i] && i+j < N; ++j){
        		dp[i+j] = min(dp[i+j], dp[i]+1);
        	}
        }
        return dp[N-1];
    }
};

int main(){
	Solution solution;
	vector<int> nums{2, 3, 1, 1, 4};
	cout << solution.jump(nums) << endl;
}