class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for(int n:nums){
            if(s.contains(n)){
                return n;
            }else{
                s.add(n);
            }
        }
        return -1;
    }
}