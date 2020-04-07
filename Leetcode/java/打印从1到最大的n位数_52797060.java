// 快速幂
class Solution {
    public int fast_pow(int base,int index){
        int ans = 1;
        while(index>0){
            if(index%2==1){
                ans*=base;
            }
            index/=2;
            base*=base;
        }
        return ans;
    }
    public int[] printNumbers(int n) {
        int sz = fast_pow(10,n)-1;
        int[] ans = new int[sz];
        for(int i=0;i<sz;++i){
            ans[i] = i+1;
        }
        return ans;
    }
}