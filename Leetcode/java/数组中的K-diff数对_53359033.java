class Solution {
    // 排序后用双指针
    public int findPairs(int[] nums, int k) {
        if(nums.length==0 || k<0){
            return 0;
        }
        int ans = 0;
        Arrays.sort(nums);
        if(k==0){
            boolean visited = false; 
            int temp = nums[0];
            for(int i=1;i<nums.length;i++){
                if(temp==nums[i] && !visited){
                    ans++;
                    visited = true;
                }else if(temp!=nums[i]){
                    temp = nums[i];
                    visited = false;
                }
            }
            return ans;
        }
        int fast = 0, slow = 0;
        while(fast < nums.length){
            if(nums[fast]-nums[slow]<k){
                while(fast+1 < nums.length && nums[fast+1]==nums[fast]){
                    fast++;
                }
                fast++;
            }else if(nums[fast]-nums[slow]>k){
                while(slow<fast && nums[slow+1]==nums[slow]){
                    slow++;
                }
                slow++;
            }else{
                ans++;
                while(fast+1 < nums.length && nums[fast+1]==nums[fast]){
                    fast++;
                }
                fast++;
            }
        }
        return ans;
    }
}