class Solution {
 struct comp{
     bool operator()(const vector<int>& iteratorL, const vector<int>& iteratorR){
         return iteratorL[0] < iteratorR[0];
     }
 };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        
        vector<vector<int>> result;
        if(intervals.size() == 0)
            return result;
        vector<int> temp = intervals[0];
        for(auto& interval : intervals){
            if(temp[1] >= interval[0]){
                temp[1] = max(temp[1], interval[1]);
            }else{
                result.emplace_back(temp);
                temp = interval;
            }
        }
        result.emplace_back(temp);
        return result;
    }
};