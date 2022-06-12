public class Solution {
    public int MaximumUniqueSubarray(int[] nums) {
        var mp = new HashSet<int>();
        int l = 0;
        int r = 0;
        int len = nums.Length;
        int sum = 0;
        int mx = 0;
        for( ; l<=r && r < len ; ) {
            int x = nums[r];
            while(mp.Contains(x)){
                mp.Remove(nums[l]);
                sum-=nums[l];
                l++;
            }
            mp.Add(nums[r]);
            sum+=nums[r++];
            mx = Math.Max(mx,sum);
        }
        
        return mx;
    }
}
