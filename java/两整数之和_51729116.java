class Solution {
    public int getSum(int a, int b) {
        int ans = a^b;
        int carry = (a&b)<<1;
        // 因为不能确保 不进位和 与 进位数字 相加不会产生进位
        while(carry!=0){
            int temp = (ans&carry)<<1;
            ans = ans ^ carry;
            carry = temp;
        }
        return ans;
    }
}