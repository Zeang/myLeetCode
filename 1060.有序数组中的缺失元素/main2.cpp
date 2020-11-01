class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int d = 0;
        for (int i = 1; i < nums.size(); ++i) {
            d += max(0, nums[i] - nums[i - 1] - 1);
            if (d >= k) {
                return nums[i] - 1 - (d - k);
            }
        }
        return nums.back() + k - d;
    }
};