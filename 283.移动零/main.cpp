class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        int len = nums.size();
        while(fast < len){
            if(nums[fast] != 0){
                if(fast != slow){
                    swap(nums[fast], nums[slow]);
                }
                ++slow;
            }
            ++fast;
        }
        return;
    }
};