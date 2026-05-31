// greedy，只在最低點買進
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int lowest = prices[0];
        for(int i = 0; i < prices.size(); i++){
            lowest = min(lowest, prices[i]);
            maxprofit = max(maxprofit, prices[i] - lowest);
        }
        return maxprofit;
    }
};
