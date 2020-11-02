class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int prev = INT_MIN;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                ++i;
            }else if(nums1[i] > nums2[j]){
                ++j;
            }else{
                if(nums1[i] != prev){
                    prev = nums1[i];
                    result.emplace_back(prev);
                }
                ++i, ++j;
            }
        }
        return result;
    }
};
