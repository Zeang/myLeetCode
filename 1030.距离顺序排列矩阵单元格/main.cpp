class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> matrix(R, vector<int>(C, 1));
        vector<vector<int>> result;
        queue<vector<int>> q;
        q.push({r0, c0});
        int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        matrix[r0][c0] = 0;
        while(!q.empty()){
            int count = q.size();
            while(count--){
                vector<int> temp = q.front();
                q.pop();
                result.emplace_back(temp);
                for(int i = 0; i < 4; ++i){
                    if(temp[0] + arr[i][0] >= 0 && temp[0] + arr[i][0] < R
                    && temp[1] + arr[i][1] >= 0 && temp[1] + arr[i][1] < C
                    && matrix[temp[0]+arr[i][0]][temp[1]+arr[i][1]]){
                        q.push({temp[0] + arr[i][0], temp[1] + arr[i][1]});
                        matrix[temp[0]+arr[i][0]][temp[1]+arr[i][1]] = 0;
                    }
                }
            }
        }
        return result;
    }
};