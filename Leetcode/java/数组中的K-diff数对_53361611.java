class Solution {
    // 排序后用双指针
    public int findPairs(int[] nums, int k) {
        if(nums.length==0 || k<0){
            return 0;
        }
        Set<Integer> diff = new HashSet<>();
        Set<Integer> visited = new HashSet<>();
        for(int x:nums){
            if(visited.contains(x-k)){
                diff.add(x-k);
            }
            if(visited.contains(x+k)){
                diff.add(x);
            }
            visited.add(x);
        }

        return diff.size();
    }
}