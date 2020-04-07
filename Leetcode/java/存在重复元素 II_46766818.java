// 之前的方法在哈希表中加入了所有遇到的nums元素
// 其实只需要用哈希表维护一个k大小的窗口就行了
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        for(int i=0;i<nums.length;++i){ 
            if(s.contains(nums[i])){
                return true;
            }else{
                s.add(nums[i]);
                if(s.size()>k){
                    s.remove(nums[i-k]); // 说明一直没有碰到合法的重复，所以窗口一定是无间隔存的
                }
            }
        }
        return false;
    }
}