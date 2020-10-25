#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int index = 0;
        int prevNum = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > prevNum){
                prevNum = nums[i];
                nums[index++] = nums[i];
                // swap(nums[i], nums[index++]);
            }
        }
        return index;
    }
};

int main(){
	Solution solution;
	vector<int> v = {0,0,1,1,1,2,2,3,3,4};
	int result = solution.removeDuplicates(v);
	cout << result << endl;
	for(int i = 0; i < result; ++i)
		cout << v[i] << " ";
}