class Solution {
    // 依次判断各位是不是1
    public int bitwiseComplement(int N) {
        if(N==0){
            return 1;
        }
        int tmp = N;
        int ans = 0;
        int i =0;
        while(tmp>0){
            if((tmp&1)==0){
                ans+=Math.pow(2,i);
            }
            tmp = tmp>>>1;
            ++i;
        }
        return ans;
    }
}