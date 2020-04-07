class Solution {
    public int findUnsortedSubarray(int[] nums) {
        boolean flag = false;
        int start = nums.length, end = 0;
        int min=Integer.MAX_VALUE, max=-Integer.MAX_VALUE;
        for(int i=1;i<nums.length;++i){
            if(nums[i]<nums[i-1]){
                flag = true;
            }
            if(flag){
                min = Math.min(min,nums[i]);
            }
        }
        flag = false;
        for(int i=nums.length-2;i>=0;--i){
            if(nums[i+1]<nums[i]){
                flag = true;
            }
            if(flag){
                max = Math.max(max,nums[i]);
            }
        }

        for(int i=0;i<nums.length;++i){
            if(nums[i]>min){
                start = i;
                break;   
            }
        } 
        for(int i=nums.length-1;i>=0;--i){
            if(nums[i]<max){
                end = i;
                break;
            }
        }
        return (end-start<0)?0:(end-start+1);
    }
}