#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;

        int first = 0;
        int len = nums.size();
        while(len > 0){
            int half = len >> 1;
            int middle = first + half;
            if(nums[middle] < target){
                first = middle+1;
                len -= half+1;
            }else{
                len = half;
            }
        }
        if(first == nums.size() || nums[first] != target)
            return {-1, -1};
        result.emplace_back(first);

        first = 0;
        len = nums.size();
        while(len > 0){
            int half = len >> 1;
            int middle = first + half;
            if(nums[middle] > target){
                len = half;
            }else{
                first = middle+1;
                len -= half+1;
            }
        }
        result.emplace_back(first-1);

        return result;
    }
};

int main(){
	Solution solution;
	vector<int> v{5, 7, 7, 8, 8, 10};
	vector<int> result = solution.searchRange(v, 6);
	for(auto s : result)
		cout << s << " ";

}