class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        int start = nums.length, end = 0;
        for(int i=0;i<nums.length;++i){
            if(nums[i]!=sorted[i]){
                start = Math.min(i,start);
                end = Math.max(i,end);
            }
        } 
        return (end-start>0)?(end-start+1):0;
    }
}