class Solution {
    public int arrangeCoins(int n) {
        double nn = n;
        int ans = (int) Math.floor(Math.sqrt(2*nn+1/4.0)-1/2.0);
        return ans;
    }
}