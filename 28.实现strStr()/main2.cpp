#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	return haystack.find(needle);
    }
};


int main(){
	Solution solution;
	int result = solution.strStr("hello", "ll");
	cout << result << endl;
}