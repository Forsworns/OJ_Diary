// 排序后比较或直接用哈希
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int[] temp = new int[Math.max(nums1.length,nums2.length)];
        int idx = 0, p1 = 0, p2 = 0;
        while(p1<nums1.length && p2<nums2.length){
            if(nums1[p1]<nums2[p2]){
                p1++;
            }else if(nums1[p1]>nums2[p2]){
                p2++;
            }else{
                temp[idx] = nums1[p1];
                idx++;
                while(nums1[p1]==nums2[p2]){
                    p1++;
                    if(p1>=nums1.length){
                        break;
                    }
                }
            }
        }

        int[] ans = new int[idx]; 
        for(int i=0;i<idx;++i){
            ans[i] = temp[i];
        }
        return ans;
    }
}