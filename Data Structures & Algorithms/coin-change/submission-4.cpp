// dp[] 一路從 1 元看最小組出的硬幣數，dp[i] 代表組出 i 元的最小硬幣數
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if(dp[amount] > amount) return -1;
        else return dp[amount];
    }
};
