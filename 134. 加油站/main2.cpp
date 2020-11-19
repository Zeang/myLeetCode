#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for(int i = 0; i < len; ++i){
            int count = 0, j = i;
            int num = 0;
            while(count < len){
                num += gas[j] - cost[j];
                if(num < 0)
                    break;
                j = (j+1)%len;
                ++count;
            }
            if(count == len)
                return i;
            i += count;
        }

        return -1;
    }
};

int main(){
	cout << "hello" << endl;
	vector<int> gas{1,2,3,4,5};
	vector<int> cost{3,4,5,1,2};

	Solution solution;
	cout << solution.canCompleteCircuit(gas, cost) << endl;

}