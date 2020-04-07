
class Solution {
    private void swap(int i, int j, int[] nums){
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }

    public int findRepeatNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                swap(i,nums[i],nums);
            }
        }
        throw new IllegalArgumentException("Cannot find the repetitive number!");
    }
}
