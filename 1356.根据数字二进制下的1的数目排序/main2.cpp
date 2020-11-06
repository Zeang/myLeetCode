#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            return make_pair(bitset<32>(a).count(), a) < make_pair(bitset<32>(b).count(), b);
        });
        return arr;
    }
};

int main(){
	vector<int> nums = {2,3,5,7,11,13,17,19};
	Solution solution;
	vector<int > result = solution.sortByBits(nums);
	for(auto num : result)
		cout << num << " ";
}