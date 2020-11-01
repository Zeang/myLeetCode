#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string temp;
        string result = "1";
        for(int i = 1; i < n; ++i){
            temp = move(result);
            result = "";
            char prev = temp[0];
            int count = 1;
            for(int j = 1; j < temp.size(); ++j){
                if(prev == temp[j]){
                    count++;
                }else{
                    result += to_string(count);
                    result += prev;
                    prev = temp[j];
                    count = 1;
                }
            }
            result += to_string(count);
            result += prev;
        }

        return result;
    }
};

int main(){
	Solution solution;
	for(int i = 1; i <= 30; ++i)
		cout << solution.countAndSay(i) << endl;

	return 0;
}