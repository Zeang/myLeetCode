class Solution {
    int N = 0;
public:
    void rotate(vector<vector<int>>& matrix) {
        N = matrix.size();
        if(N == 0)
            return;
        for(int i = 0; i < N-1; ++i)
            for(int j = i; j < N-1-i; ++j)
                vertexRotate(matrix, i, j);
        return;
    }

    void vertexRotate(vector<vector<int>>& matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[N-1-j][i];
        matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
        matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
        matrix[j][N-1-i] = temp;
    }
};