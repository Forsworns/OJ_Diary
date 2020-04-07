// 对n-1个元素做加法，等于对一个做减法
// 所以把每个数都减少到最小值就行了
class Solution {
    public int minMoves(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int min = nums[0];
        int sum = 0;
        for(int x:nums){
            if(x<min){
                min = x;
            }
            sum+=x;
        }
        return sum-nums.length*min;
    }
}