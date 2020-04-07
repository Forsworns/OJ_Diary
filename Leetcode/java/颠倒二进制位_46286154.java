public class Solution {
    // 考的是位运算
    // you need treat n as an unsigned value
    static final short DIGIT = 32;
    public int reverseBits(int n) {
        int ans=0;
        for(short i=0;i<DIGIT;++i){
            int t = 1<<i;
            int r = (t&n)>>>i;
            ans  = (ans<<1) + r;
        }
        return ans;
    }
}