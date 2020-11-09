#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, vector<int>> m;
        int len = points.size();
        for(int i = 0; i < len; ++i){
            int temp = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            m.insert(pair<int, vector<int>>(temp, move(points[i])));
        }
        vector<vector<int>> result;
        int i = 0;
        for(auto a : m){
        	if(++i > K)
        		break;
        	result.emplace_back(move(a.second));
        }

        return result;
    }
};


int main(){
	vector<vector<int>> nums{{3, 3}, {5, 1}, {-2, 4}};
	Solution solution;
	vector<vector<int>> result = solution.kClosest(nums, 2);
	for(auto s : result){
		cout << s[0] << " " << s[1] << endl;
	}
}