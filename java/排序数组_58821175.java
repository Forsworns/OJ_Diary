// 归并排序
class Solution {
    private int[] merge(int[] nums, int l, int r){
        final int N = r-l+1;
        int[] ans = new int[N];
        if(N==1){
            ans[0] = nums[l];
            return ans;
        } 
        int[] left = merge(nums,l,(l+r)/2);
        int[] right = merge(nums,(l+r)/2+1,r);
        int i =  0, j = 0, k = 0;
        while(i<left.length && j<right.length){
            if(left[i]<right[j]){
                ans[k] = left[i];
                i++;
            }else{
                ans[k] = right[j];
                j++;
            }
            k++;
        }
        while(i<left.length){
            ans[k] = left[i];
            i++;
            k++;
        }
        while(j<right.length){
            ans[k] = right[j];  
            j++;      
            k++;    
        }
        return ans;
    }

    public int[] sortArray(int[] nums) {
        final int N = nums.length; 
        int[] ans = merge(nums, 0, N-1);
        return ans;
    }
}