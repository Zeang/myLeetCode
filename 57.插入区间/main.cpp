#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      	if(intervals.size() == 0)
            return {newInterval};

		int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> result;
        bool flag = true, flag2 = true;

        for(int i = 0; i < intervals.size(); ++i){
            if(flag){
                if(intervals[i][1] < left){
                    result.emplace_back(intervals[i]);
                }else{
                    left = min(left, intervals[i][0]);
                    flag = false;
                    --i;
                }
            }else{
                if(intervals[i][0] > right){
                    if(flag2){
                        result.push_back({left, right});
                        flag2 = false;
                        --i;
                    }else
                        result.emplace_back(intervals[i]);
                }else
                    right = max(right, intervals[i][1]);
            }
        }
        if(flag2)
        	result.push_back({left, right});
        return result;
    }
};

int main(){
	vector<vector<int>> nums{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	vector<int> v{4, 8};
	Solution solution;
	vector<vector<int>> result = solution.insert(nums, v);
	for(auto num : result){
		cout << num[0] << " " << num[1] << endl;
	}

	return 0;
}