class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool arr1[9][9] = {false};
        bool arr2[9][9] = {false};
        bool arr3[3][3][9] = {false};

        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                else if(arr1[i][board[i][j]-'1'])
                    return false;
                else
                    arr1[i][board[i][j]-'1'] = true;
            }

        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j){
                if(board[j][i] == '.')
                    continue;
                else if(arr2[i][board[j][i]-'1'])
                    return false;
                else
                    arr2[i][board[j][i]-'1'] = true;
            }

        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                for(int m = 0; m < 3; ++m)
                    for(int n = 0; n < 3; ++n){
                        if(board[i*3+m][j*3+n] == '.')
                            continue;
                        else if(arr3[i][j][board[i*3+m][j*3+n]-'1'])
                            return false;
                        else
                            arr3[i][j][board[i*3+m][j*3+n]-'1'] = true;
                    }
        
        return true;
    }
};