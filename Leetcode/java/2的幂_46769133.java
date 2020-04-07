// 位运算的思路，检查每一位是否为1
class Solution {
    public boolean isPowerOfTwo(int n) {
        boolean ans = false;
        while(n>0){
            if((n&1)==1){
                if(ans){
                    return false;
                }else{
                    ans = true; 
                }
            }
            n = n>>1;
        }
        return ans;
    }
}