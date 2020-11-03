class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        bool flag = false;

        for(int i = 0; i < A.size()-1; ++i){
            if(A[i] < A[i+1]){
                if(flag)
                    return false;
            }else if(A[i] > A[i+1]){
                if(i == 0)
                    return false;
                else
                    flag = true;
            }else
                return false;
        }
        return flag;
    }
};