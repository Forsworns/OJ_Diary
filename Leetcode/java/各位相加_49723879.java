class Solution {
    public int addDigits(int num) {
        // 从十几，二十几开始，数学归纳法
        return 1+(num-1)%9;
    }
}