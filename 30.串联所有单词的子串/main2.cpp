#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) return {};
        unordered_map<string, int> wordcnt;
        for (auto& w : words) {
            wordcnt[w]++;
        }
        int len = words[0].size();

        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int left = i;
            int right = left;
            int cnt = 0;

            unordered_map<string, int> window;
            while (left + words.size() * len <= s.size()) {
                string temp = "";
                while (cnt < words.size()) {
                    temp = s.substr(right, len);
                    if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
                    window[temp]++;
                    cnt++;
                    right += len;
                }

                if (window == wordcnt) {
                    ans.push_back(left);
                }

                if (wordcnt.find(temp) != wordcnt.end()) {
                    window[s.substr(left, len)]--;
                    cnt--;
                    left += len;
                }
                else {
                    right += len;
                    left = right;
                    cnt = 0;
                    window.clear();
                }
            }
        }
        return ans;
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