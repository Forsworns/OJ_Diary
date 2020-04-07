// 已知范围，桶排序
class Solution {
    public int[] sortArray(int[] nums) {
        final int N = nums.length;
        final int B = 100001; 
        int[] bucket = new int[B];
        for(int i=0;i<N;++i){
            bucket[nums[i]+50000]++;
        }
        int i=0;
        for(int b=0;b<B;b++){
            for(int j=0;j<bucket[b];++j){
                nums[i] = b-50000;
                i++;
            }
        }
        return nums;
    }
}