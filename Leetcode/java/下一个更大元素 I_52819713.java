class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer> m = new HashMap<>();
        Queue<Integer> q = new PriorityQueue<>();
        for(int x:nums2){
            while(q.size()!=0 && q.peek()<x){
                m.put(q.poll(),x);
            }
            q.add(x);
        }
        while(q.size()!=0){
            m.put(q.poll(),-1);
        }
        int[] ans = new int[nums1.length];
        for(int i=0;i<nums1.length;++i){
            ans[i] = m.get(nums1[i]);
        }
        return ans;
    }
}