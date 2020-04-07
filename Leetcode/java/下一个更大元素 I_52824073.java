// 上一个解法用优先级队列，应该考虑单调栈，可以减少时间消耗，否则最差情况下需要一直调整最小堆
// 原因就是其实不需要顺序，只需要确保数据结构中的元素总是大于当前元素就行了
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer> m = new HashMap<>();
        Stack<Integer> s = new Stack<>();
        for(int x:nums2){
            while(s.size()!=0 && s.peek()<x){ 
                m.put(s.pop(),x);
            }
            s.add(x);
        }
        while(s.size()!=0){
            m.put(s.pop(),-1);
        }
        int[] ans = new int[nums1.length];
        for(int i=0;i<nums1.length;++i){
            ans[i] = m.get(nums1[i]);
        }
        return ans;
    }
}