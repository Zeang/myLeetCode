#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, multiset<int>> m;
        for(auto& a : arr){
            int countTemp = count1(a);
            m[countTemp].insert(move(a));
        }

        vector<int> result;
        for(auto& a : m){
            for(auto& b : a.second){
                result.emplace_back(move(b));
            }
        }
        return result;
    }

    int count1(int a){
        int count = 0;
        while(a){
            count += a & 0x1;
            a >>= 1;
        }
        return count;
    }
};

int main(){
	vector<int> nums = {2,3,5,7,11,13,17,19};
	Solution solution;
	vector<int > result = solution.sortByBits(nums);
	for(auto num : result)
		cout << num << " ";
}