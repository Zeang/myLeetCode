#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; ++i){
        	while(nums[i] > 0 && nums[i] <= N && nums[i] != nums[nums[i]-1]){
        		swap(nums[i], nums[nums[i]-1]);
        	}
        }

        for(int i = 0; i < N; ++i){
        	if(nums[i] != i+1)
        		return i+1;
        }
        return N+1;
    }
};

int main(){
	Solution solution;
	vector<int> nums{3, 4, -1, 1};
	cout << solution.firstMissingPositive(nums) << endl;
}