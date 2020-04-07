// 排序后，算最大值与最小值的差
class Solution {
    public int minMoves(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        Arrays.sort(nums);
        int ans = 0;
        for(int i=1;i<nums.length;++i){
            ans+=(nums[i]-nums[0]);
        }
        return ans;
    }
}