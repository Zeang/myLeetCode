#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int left = 0, right = 0, end = 0;
        int result = 0;
        for(int i = 0; i < clips.size(); ++i){
            if(clips[i][0] <= left){
                right = max(right, clips[i][1]);
                if(right >= T)
                	return ++result;
            }else if(clips[i][0] <= right){
                end = max(end, clips[i][1]);
                if(end >= T)
                    return result+2;
            }else
                ++result, left = right, right = end;
        }
        return -1;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> v = {{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}};
	vector<vector<int>> v = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
	cout << solution.videoStitching(v, 11);

}