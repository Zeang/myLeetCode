#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int result = 0, prev = 0, i = 0;
        bool flag1 = false, flag2 = false;
        
        for(i = 0; i < A.size()-1; ++i){
            if(A[i] < A[i+1]){
                if(!flag1){
                    flag1 = true;
                    prev = i;
                }else if(flag2){
                    result = max(result, i-prev+1);
                    flag2 = false;
                    prev = i;
                }
            }else if(A[i] > A[i+1] && flag1){
                flag2 = true;
            }else{
                if(flag1 && flag2)
                    result = max(result, i-prev+1);
                prev = i;
                flag1 = flag2 = false;
            }
        }
        if(A[i] < A[i-1] && flag1 && flag2){
            result = max(result, i-prev+1);
        }

        return result;
    }
};

int main(){
    Solution solution;
    vector<int> v = {2, 2, 2};
    cout << solution.longestMountain(v) << endl;
}