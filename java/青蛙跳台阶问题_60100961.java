class Solution {
    public int numWays(int n) {
        int last=1,ans=1;
        for(int i=2;i<=n;++i){
            int l=last;
            last = ans;
            ans+=l;
            ans%=1000000007;
        }
        return ans;
    }
}