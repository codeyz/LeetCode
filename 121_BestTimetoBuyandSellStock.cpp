class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        vector<int> flag(prices.size(), 0);
        flag[0] = prices[0];
        for(size_t i = 1;i < prices.size(); ++i)
        {
            flag[i] = min(prices[i], flag[i - 1]);
        }
        int maxValue = 0;
        for(size_t i = 1;i < prices.size(); ++i)
        {
            maxValue = max(maxValue, prices[i] - flag[i]);
        }
        return maxValue;
    }
};
