class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+5);
        int n = coins.size();
        dp[0] = 0;
        for ( int i = 1 ; i <= amount ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if(i-coins[j]>=0) {
                    dp[i] = min ( dp[i] , 1 + dp[i-coins[j]] ); 
                }
            }
        }
        if(dp[amount]==amount+5) return -1;
        return dp[amount];
    }
};
