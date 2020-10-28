#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle.size() == 0)
    		return 0;

        for(int i = 0; i < haystack.size(); ++i){
        	int j = i, k = 0;
        	while(haystack[j++] == needle[k++])
        		if(k == needle.size())
        			return i;
        }

        return -1;
    }
};


int main(){
	Solution solution;
	int result = solution.strStr("hello", "ll");
	cout << result << endl;
}