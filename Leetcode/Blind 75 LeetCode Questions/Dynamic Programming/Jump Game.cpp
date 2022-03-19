class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next = 0;
        int n = nums.size();
        
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            int R = i+nums[i];
            next = max ( next , R );
            if(next==i) return 0;
        }
        return 1;
    }
};
