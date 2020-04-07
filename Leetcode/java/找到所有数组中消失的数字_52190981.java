class Solution {
    // 原地修改输入数组，因为输入范围是已知的，抗役把访问到的数对应位置的数字标记为负数
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for(int n:nums){
            n = Math.abs(n);
            nums[n-1] = -1*Math.abs(nums[n-1]);
        }
        for(int i=0;i<nums.length;++i){
            if(nums[i]>0){
                ans.add(i+1);
            }
        }
        return ans;
    }
}