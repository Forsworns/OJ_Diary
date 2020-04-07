class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int temp=0;
        boolean consecutive = true;
        for(int i=0;i<nums.length;++i){
            if(consecutive){
                if(nums[i]==0){
                    consecutive=false;
                    ans = Math.max(ans,temp);
                    temp = 0;
                }else{
                    temp++;
                }     
            }else{
                if(nums[i]==1){
                    temp = 1;
                    consecutive = true;
                }
            }
        }
        ans = Math.max(ans,temp);
        return ans;
    }
}