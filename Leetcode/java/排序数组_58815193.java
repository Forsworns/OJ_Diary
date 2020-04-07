// 冒泡排序
class Solution {
    public int[] sortArray(int[] nums) {
        final int N = nums.length; 
        for(int i=0;i<N;++i){
            int min = nums[i];
            int pos = i;
            for(int j=i;j<N;++j){
                if(min>nums[j]){
                    min = nums[j];
                    pos = j;
                }
            }
            nums[pos] = nums[i];
            nums[i] = min;
        }
        return nums;
    }
}