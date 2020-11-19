class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dpleft(len, 0);
        vector<int> dpright(len, 0);

        int minPrice = INT_MAX;
        int maxDiff = INT_MIN;
        for(int i = 0; i < len; ++i){
            minPrice = min(minPrice, prices[i]);
            maxDiff = max(prices[i]-minPrice, maxDiff);
            dpleft[i] = maxDiff;
        }
        
        int maxPrice = INT_MIN;
        maxDiff = INT_MIN;
        for(int i = len-1; i >= 0; --i){
            maxPrice = max(maxPrice, prices[i]);
            maxDiff = max(maxPrice - prices[i], maxDiff);
            dpright[i] = maxDiff;
        }

        maxDiff = INT_MIN;
        for(int i = 0; i < len; ++i){
            maxDiff = max(maxDiff, dpleft[i] + dpright[i]);
        }

        return maxDiff;
    }
};