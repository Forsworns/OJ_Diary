class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        // 排序后双指针
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int[] temp = new int[Math.max(nums1.length,nums2.length)];
        int idx = 0, i1=0,i2=0;

        while(i1<nums1.length&&i2<nums2.length){
            if(nums1[i1]<nums2[i2]){
                i1++;
            }else if(nums1[i1]>nums2[i2]){
                i2++;
            }else{
                temp[idx++] = nums1[i1];
                i1++;
                i2++;
            }
        }

        int[] ans = new int[idx];
        for(int i=0;i<idx;++i){
            ans[i] = temp[i];
        }
        return ans;
    }
}