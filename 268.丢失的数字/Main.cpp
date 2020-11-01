#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            result ^= i ^ nums[i];
        return result;
    }
};

int main(){
	vector<int> nums{9,6,4,2,3,5,7,0,1};
	Solution solution;
	cout << solution.missingNumber(nums) << endl;
	return 0;
}