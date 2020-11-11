class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), count = 0;
        for(int i = len-1; i >= 0; --i){
            if(s[i] == ' '){
                if(len== i+1+count)
                    ++count;
                else
                    return len-i-1-count;

            }
        }
        return len-count;
    }
};