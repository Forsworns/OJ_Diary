class Solution {
    public int arrayPairSum(int[] nums) {
        int[] bucket = new int[20001];
        final int I = 10000;
        for(int i=0;i<bucket.length;++i){
            bucket[i] = 0;
        }
        for(int n:nums){
            bucket[n+I]++;
        }
        int prev_remain = 0;
        int ans = 0;
        for(int i=-10000;i<=10000;++i){
            if(bucket[i+I]!=0){ // 0的桶会影响下面的等式
                ans+=(bucket[i+I]+1-prev_remain)/2*i; //如果前面有剩余的，需要b/2个；否则需要(b+1)/2
                prev_remain = (bucket[i+I]-prev_remain)%2; // 如果有剩余的，遇到奇数将会配对，不再有剩余；否则产生新的剩余
            }
        }
        return ans;
    }
}