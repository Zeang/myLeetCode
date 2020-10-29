#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int index = -1;
        for(int i = len-2; i >= 0; --i)
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        if(index != -1){
        for(int i = len-1; i > index; --i)
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        sort(nums.begin() + index+1, nums.end());
    }
};

int main(){
	Solution solution;
	vector<int> nums{1, 1, 5};
	solution.nextPermutation(nums);
	for(auto num : nums)
		cout << num << " ";
	cout << endl;
	return 0;
}