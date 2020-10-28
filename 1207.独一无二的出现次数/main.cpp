#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> nums(2001, 0);
        for(auto a : arr){
            ++nums[a+1000];
        }
        set<int> s;
        for(auto num : nums){
            if(num != 0){
                auto it = s.find(num);
                if(it == s.end()){
                    s.insert(num);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
	vector<int> arr{-3,0,1,-3,1,1,1,-3,10,0};
	Solution solution;
	cout << solution.uniqueOccurrences(arr) << endl;

}