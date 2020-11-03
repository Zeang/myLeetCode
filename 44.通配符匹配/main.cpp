#include <iostream>
#include <vector>
#include <string>


// dp[i][j] = dp[i][j-1]
// dp[i][j] = dp[i-n][j-1]
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= M; ++i){
        	dp[i][0] = 0;
        }
        for(int i = 0; i < N; ++i){
        	if(p[i] == '*')
        		dp[0][i+1] = dp[0][i];
        }
        for(int j = 0; j < N; ++j){
        	for(int i = 0; i < M; ++i){
        		if(p[j] == '?' || p[j] == s[i]){
        			dp[i+1][j+1] = dp[i][j];
        		}else if(p[j] == '*'){
        			for(int k = i+1; k >= 0; --k){
        				dp[i+1][j+1] |= dp[k][j];
        			}
        		}else{
        			dp[i+1][j+1] = 0;
        		}
        	}
        }
        return dp[M][N];
    }
};

int main(){
	string s = "acdcb";
	string p = "a*c?b";
	Solution solution;
	cout << boolalpha << solution.isMatch(s, p) << endl;

}