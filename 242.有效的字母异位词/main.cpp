#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> ss;
        multiset<char> ts;
        for(auto a : s){
            ss.insert(a);
        }

        for(auto a : t){
            ts.insert(a);
        }
        return ss == ts;
    }
};

int main(){
	Solution solution;
	string s = "rat";
	string t = "car";
	cout << solution.isAnagram(s, t) << endl;
}