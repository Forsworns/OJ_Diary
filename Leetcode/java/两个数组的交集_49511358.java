// 排序后比较或直接用哈希
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for(int x:nums1){
            set1.add(x);
        }
        for(int x:nums2){
            if(set1.contains(x)){
                set2.add(x);
            }
        }
        int[] ans = new int[set2.size()];
        Iterator<Integer> it = set2.iterator();
        for(int i=0;i<set2.size();++i){
            ans[i] = it.next();
        }
        return ans;
    }
}