class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int first = 0, len = N;
        while(len > 0){
            int half = len >> 1;
            int middle = first + half;
            if(citations[middle] + middle< N)
                first = middle+1, len -= half+1;
            else
                len = half;
        }
        return N-first;
    }
};