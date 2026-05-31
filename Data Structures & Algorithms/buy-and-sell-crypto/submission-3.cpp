class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int left = 0;
        int right = 1;

        while(right < prices.size()){
            if(prices[left] < prices[right]){
                maxprofit = max(maxprofit, prices[right] - prices[left]);
            }
            else{
                left = right;
            }
            right++;
        }
        return maxprofit;
    }
};
