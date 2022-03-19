class Solution {
public:
    vector<int> dp;
    
    int recur ( int ind ) {
        if(ind==0) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int way = 0;
        if(ind-1>=0) way+=recur(ind-1);
        if(ind-2>=0) way+=recur(ind-2);
        return dp[ind] = way;
    }
    
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return recur(n);
    }
};
