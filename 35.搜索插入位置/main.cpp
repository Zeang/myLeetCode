class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0, len = nums.size();
        while(len > 0){
            int half = len >> 1;
            int middle = first + half;
            if(nums[middle] < target)
                first = middle+1, len -= half+1;
            else
                len = half;
        }
        return first;
    }
};