#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        });
        return {points.begin(), points.begin() + K};
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