class Solution {
public:
    int arr[201];
    vector<int> dp;
    int n;
    int x;
    
    int recur ( int rem ){
        if(rem==0) return 1;
        if(dp[rem]!=-1) return dp[rem];
        int way = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if(rem-arr[i]>=0) way+=recur(rem-arr[i]);
        } 
        return dp[rem] = way;  
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n =  nums.size();
        
        for ( int i = 0 ; i < n ; ++i ) arr[i] = nums[i];
        
        dp.resize(1001,-1);
        x = target;
        return recur ( target );
    }
};
