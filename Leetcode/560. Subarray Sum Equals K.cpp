class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long subarr = 0 , sum = 0;
        
        map < long long , long long > mp;
        mp[0] = 1;
        for ( long long i = 0 ; i<nums.size() ; i++ ){
             sum+=nums[i];
             subarr+=mp[sum-k];
             mp[sum]++;
        }
        return subarr;
    }
};
