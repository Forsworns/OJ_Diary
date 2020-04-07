// 快排
class Solution {
    private void quick(int[] nums, int left, int right){
        if(left==right){
            return;
        }
        int guard = nums[left], middle=left;
        int temp=guard, pos=left;
        int l=left+1, r=right;
        while(l<=r){
            while(l<=middle && nums[l]<=guard){
                l++;
            }
            if(l<=middle){
                nums[middle] = nums[l];
                middle = l;
            }
            while(r>=middle && nums[r]>=guard){
                r--;
            }
            if(r>=middle){
                nums[middle] = nums[r];
                middle = r;
            }
        }
        nums[middle] = guard; 
        if(middle>left){
            quick(nums,left,middle-1);
        }
        if(middle<right){
            quick(nums,middle+1,right);
        }
    }

    public int[] sortArray(int[] nums) {
        final int N = nums.length;
        quick(nums,0,N-1);
        return nums;
    }
}