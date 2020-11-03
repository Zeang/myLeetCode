#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int N = nums.size();
        for(int i = 0; i < N; ++i){
        	if(nums[i] <= 0){
        		nums[i] = N+1;
        	}
        }
        for(int i = 0; i < N; ++i){
        	int index = abs(nums[i]);
        	if(index <= N){
        		nums[index-1] = -abs(nums[index-1]);
        	}
        }
        for(int i = 0; i < N; ++i){
        	if(nums[i] > 0){
        		return i+1;
        	}
        }
        return N+1;
    }
};

int main(){
	Solution solution;
	vector<int> nums{3, 4, -1, 1};
	cout << solution.firstMissingPositive(nums) << endl;
	return 0;
}