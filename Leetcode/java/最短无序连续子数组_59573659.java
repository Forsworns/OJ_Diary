class Solution {
    public int findUnsortedSubarray(int[] nums) {
        Stack<Integer> s = new Stack<>();
        int start = nums.length, end = 0;
        for(int i=0;i<nums.length;++i){
            while(!s.empty()&&nums[s.peek()]>nums[i]){
                start = Math.min(start,s.pop());
            }
            s.push(i);
        } 
        s.clear();
        for(int i=nums.length-1;i>=0;--i){
            while(!s.empty()&&nums[s.peek()]<nums[i]){
                end = Math.max(end,s.pop());
            }
            s.push(i);
        } 
        return (end-start>0)?(end-start+1):0;
    }
}