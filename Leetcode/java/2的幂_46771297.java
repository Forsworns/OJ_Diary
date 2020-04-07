// n & (n-1) 将n的最后一个1设为0
// n & (-n) 获取n的最后一个1所对应的数字
class Solution {
  public boolean isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n-1)) == 0 || (n & (-n)) == n; // 两个都可以用！
  }
}