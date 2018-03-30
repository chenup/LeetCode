class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MIN;
        int pre_sell = 0;
        int pre_buy = 0;
        for(auto it : prices)
        {
        	pre_buy = buy;
        	buy = max(pre_sell - it, pre_buy);
        	pre_sell = sell;
        	sell = max(pre_sell, pre_buy + it);
        }
        return sell;
    }
};