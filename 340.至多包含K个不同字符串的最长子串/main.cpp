class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0)
            return 0;
        int arr[128] = {0};
        int left = 0, right = 0;
        int result = 0, count = 0;
        while(right < s.size()){
        	int index = s[right]-' ';
            ++arr[index];
            ++right;
            if(arr[index] == 1){
                ++count;
                while(count > k){
                    --arr[s[left]-' '];
                    if(arr[s[left++]-' '] == 0){
                        --count;
                    }
                }
            }
            result = max(right - left, result);
        }
        return result;
    }
};