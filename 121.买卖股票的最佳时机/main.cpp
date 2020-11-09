class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int diff = 0;
        int buy = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > buy){
                diff = max(prices[i]-buy, diff);
            }else{
                buy = prices[i];
            }
        }

        return diff;
    }
};