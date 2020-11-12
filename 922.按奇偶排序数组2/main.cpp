#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
    	int len = A.size();
        int odd = 1, even = 0;
        while(odd < len && even < len){
        	while(odd < len && (A[odd] & 0x1) == (odd & 0x1)) odd+=2;
        	while(even < len && (A[even] & 0x1) == (even & 0x1)) even +=2;
        	if(odd < len && even < len)
        		swap(A[odd], A[even]);
        	odd += 2, even += 2;
        }
        return A;
    }
};

int main(){
	vector<int> nums{2,3,1,1,4,0,0,4,3,3};
	Solution solution;
	vector<int> result = solution.sortArrayByParityII(nums);
	for(auto r : result)
		cout << r << " ";
}