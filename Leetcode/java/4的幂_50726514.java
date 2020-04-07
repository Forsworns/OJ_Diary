// 循环递归是模4，不能用的话就要用 x&(x-1)==0 判断是否为2的倍数
class Solution {
    public boolean isPowerOfFour(int num) {
        if(num>0 && (num&(num-1))==0 && (num&0xaaaaaaaa)==0){
            return true;
        }else{
            return false;
        }
    }
}