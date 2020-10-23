#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int diff = INT_MAX;
        int N = nums.size();
        sort(nums.begin(), nums.end());        
        for(int i = 0; i < N-2; ++i){
            int tempTarget = target - nums[i];
            int j = i+1, k = N-1;
            while(j < k){
                int hhh = nums[j] + nums[k] - tempTarget;
                if(hhh < 0){
                    if(diff + hhh > 0)
                        diff = -hhh, result = target + hhh;
                    ++j;
                }else if(hhh > 0){
                    if(diff > hhh)
                        diff = hhh, result = target + hhh;
                    --k;
                }else{
                    return target;
                }
            }
        }

        return result;
    }
};

int main(){
	Solution solution;
	vector<int> v = {-1, 2, 1, -4};
	cout << solution.threeSumClosest(v, 5);
}