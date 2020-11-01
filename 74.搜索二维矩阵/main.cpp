#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(M == 0)
            return false;
        int N = matrix[0].size();
        if(N == 0)
            return false;
        
        int first = 0;
        int len = M;
        while(len > 0){
            int half = len >> 1;
            int middle = first + half;
            if(matrix[middle][0] < target){
                first = middle+1;
                len -= half+1;
            }else{
                len = half;
            }
        }

        if(first != M && matrix[first][0] == target)
            return true;
        else if(first == 0)
            return false;
        
        int col = first-1;
        first = 0;
        len = N;
        while(len > 0){
            int half = len >> 1;
            int middle = first + half;
            if(matrix[col][middle] < target){
                first = middle+1;
                len -= half+1;
            }else{
                len = half;
            }
        }
        if(first == N || matrix[col][first] != target)
            return false;
        else
            return true;
    }
};

int main(){
    vector<vector<int>> matrix = {{1, 3}};
    Solution solution;
    cout << solution.searchMatrix(matrix, 3) << endl;
}