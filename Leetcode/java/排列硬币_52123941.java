class Solution {
    public int arrangeCoins(int n) {
        int ans = 0;
        int i=1;
        n-=i;
        while(n>=0){
            ans++;
            i++;
            n-=i;
        }
        return ans;
    }
}