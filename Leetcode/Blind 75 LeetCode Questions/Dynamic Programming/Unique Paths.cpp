class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(n+1);
        for ( int i = 0 ; i < n ; ++i ) {
            dp[i].resize(m+1);
            for ( int j = 0 ; j < m ; ++j ) {
            if(j==0) dp[i][j] = 1;
            else if ( i == 0 ) dp[i][j] = 1;
            else dp[i][j] = 0;
            }
        }
        
        for ( int i = 1 ; i<n ; ++i ) {
            for ( int j = 1 ; j<m ; ++j ) {
                if(i-1>=0) dp[i][j]+=dp[i-1][j];
                if(j-1>=0) dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
