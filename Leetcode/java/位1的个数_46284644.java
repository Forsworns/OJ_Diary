public class Solution {
    // you need to treat n as an unsigned value
    static final int DIGITS = 32;
    public int hammingWeight(int n) {
        short ans = 0;
        for(int i=0;i<DIGITS;++i){
            int num = 1<<i;
            if((num & n) >>> i == 1) {
                ans++;
            }
        }
        return ans;
    }
}