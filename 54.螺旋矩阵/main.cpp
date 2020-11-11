#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int M, N;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        M = matrix.size();
        if(M == 0)
            return {};
        N = matrix[0].size();
        if(N == 0)
            return {};
        vector<int> result;
        int half = (min(M, N)) >> 1;
        for(int i = 0; i < half; ++i){
            circular(result, matrix, i);
        }
        if(min(M, N) & 0x1){
        	if(M < N)
        		row(result, matrix, M>>1);
        	else
        		column(result, matrix, N>>1);
        }
        return result;
    }

    void circular(vector<int>& result, vector<vector<int>>& matrix, int index){
        for(int i = index; i < N-index-1; ++i)
            result.emplace_back(move(matrix[index][i]));
        for(int i = index; i < M-index-1; ++i)
            result.emplace_back(move(matrix[i][N-index-1]));
        for(int i = N-index-1; i > index; --i)
            result.emplace_back(move(matrix[M-index-1][i]));
        for(int i = M-index-1; i > index; --i)
            result.emplace_back(move(matrix[i][index]));
    }

    void row(vector<int>& result, vector<vector<int>>& matrix, int index){
    	for(int i = index; i < N-index; ++i)
    		result.emplace_back(move(matrix[index][i]));
    }

    void column(vector<int>& result, vector<vector<int>>& matrix, int index){
    	for(int i = index; i < M-index; ++i)
    		result.emplace_back(move(matrix[i][index]));
    }
};

int main(){
	vector<vector<int>> matrix{{2, 5}, {8, 4}, {0, -1}};
	Solution solution;
	vector<int> result = solution.spiralOrder(matrix);
	for(auto a : result)
		cout << a << " ";
}