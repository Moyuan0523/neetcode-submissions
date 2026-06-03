class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = amount + 1;
        int m = coins.size();

        if(amount == 0) return 1;
        if(m == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 初始化
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }

        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                // 不使用這個硬幣
                int no_curr_coin = 0;
                if(i - 1 >= 0){
                    no_curr_coin = dp[i - 1][j];
                }
                else{
                    no_curr_coin = 0;
                }
                // 使用這個硬幣
                int use_curr_coin = 0;
                if(j - coins[i] >= 0){
                    use_curr_coin = dp[i][j - coins[i]];
                }
                else{
                    use_curr_coin = 0;
                }
                dp[i][j] = no_curr_coin + use_curr_coin;
            }
        }

        return dp[m - 1][n - 1];
    }
};
