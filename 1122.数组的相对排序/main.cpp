#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        multiset<int> s;
        for(auto& num : arr1){
            s.insert(move(num));
        }
        vector<int> result;
        for(auto& num : arr2){
            while(s.find(num) != s.end()){
                auto a = s.find(num);
                result.emplace_back(*a);
                s.erase(a);
            }
        }
        for(auto& num : s){
            result.emplace_back(move(num));
        }
        return result;
    }
};

int main(){
	Solution solution;
	vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19};
	vector<int> arr2{2, 1, 4, 3, 9, 6};
	
	vector<int> result = solution.relativeSortArray(arr1, arr2);
	for(auto a : result)
		cout << a << " ";
	return 0;
}