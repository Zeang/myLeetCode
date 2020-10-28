#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int N = words.size();

        if(N == 0)
        	return result;
        int len = words[0].size();

        unordered_map<string, int> wordCount;
        for(auto& word : words){
            ++wordCount[word];
        }

        unordered_map<string, int> mtemp;
        for(int i = 0; i + N*len <= s.size(); ++i){
        	for(int j = 0; j < N; ++j){
        		string temp = s.substr(i + len*j, len);
        		auto it = wordCount.find(temp);
        		if(it == wordCount.end())
        			break;
        		else{
        			++mtemp[temp];
        		}
        	}
        	if(mtemp == wordCount)
        		result.emplace_back(i);
        	mtemp.clear();
        }

        return result;
    }
};


int main(){
	Solution solution;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words{"word","good","best","good"};
	vector<int> result = solution.findSubstring(s, words);
	for(auto s : result)
		cout << s << " ";
	cout << endl;

	return 0;
}