class Solution {
    public int missingNumber(int[] nums) {
        // 利用相同数异或为0
        int ans = nums.length;
        for(int i=0;i<nums.length;++i){
            ans^=i;
            ans^=nums[i];
        }
        return ans;
    }
}