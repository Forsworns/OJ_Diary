class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        Set<Integer> s = new HashSet<>();
        List<Integer> ans = new ArrayList<>();
        for(int n:nums){
            s.add(n);
        }
        for(int i=1;i<=nums.length;++i){
            if(!s.contains(i)){
                ans.add(i);
            }
        }
        return ans;
    }
}