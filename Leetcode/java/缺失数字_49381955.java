class Solution {
    public int missingNumber(int[] nums) {
        // 求和，用(n+1)n/2减去
        int sum = 0;
        for(int i=0;i<nums.length;++i){
            sum+=nums[i];
        }
        return nums.length*(nums.length+1)/2-sum;
    }
}