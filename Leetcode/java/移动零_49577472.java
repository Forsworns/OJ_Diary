class Solution {
    public void moveZeroes(int[] nums) {
        // 在遍历时，记录0的个数
        int count = 0;
        for(int i=0;i<nums.length;++i){
            if(nums[i]==0){
                count++;
            }else{
                nums[i-count] = nums[i];
            }
        }
        for(int i=nums.length-count;i<nums.length;++i){
            nums[i] = 0;
        }
    }
}