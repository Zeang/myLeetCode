class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> arr(len, 0);
        arr[0] = 1;
        int maxLen = 0;
        for(int i = 0; i < len; ++i){
            if(arr[i] && nums[i] + i > maxLen){
                maxLen = nums[i]+i;
                for(int j = i+1; j <= maxLen && j < len; ++j){
                    arr[j] = 1;
                }
            }
        }
        return arr[len-1];
    }
};