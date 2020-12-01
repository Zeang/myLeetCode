#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> countAB;
        for (int u: A) {
            for (int v: B) {
                ++countAB[u + v];
            }
        }
        int ans = 0;
        for (int u: C) {
            for (int v: D) {
                if (countAB.count(-u - v)) {
                    ans += countAB[-u - v];
                }
            }
        }
        return ans;
    }
};

int main(){
	Solution solution;
	vector<int> A {0, 1, -1};
	vector<int> B {-1, 1, 0};
	vector<int> C {0, 0, 1};
	vector<int> D {-1, 1, 1};
	cout << solution.fourSumCount(A, B, C, D) << endl;
}