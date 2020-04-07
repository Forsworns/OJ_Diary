// dp[n] = dp[n-1]+dp[n-2]
class Solution {
    public int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int last=1,ans=1;
        for(int i=2;i<=n;++i){
            int l=last;
            last = ans;
            ans+=l;
        }
        return ans;
    }
}