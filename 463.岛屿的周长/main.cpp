#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int M = grid.size();
        if(M == 0)
            return 0;
        int N = grid[0].size();
        if(N == 0)
            return 0;

        vector<vector<int>> arr{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int result = 0;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                if(grid[i][j]){
                    result += 4;
                    for(int k = 0; k < 4; ++k)
                        if(i + arr[k][0] < M && i + arr[k][0] >= 0
                        && j + arr[k][1] < N && j + arr[k][1] >= 0
                        && grid[i+arr[k][0]][j+arr[k][1]])
                            --result;
                }
        return result;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> v = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << solution.islandPerimeter(v) << endl;
}