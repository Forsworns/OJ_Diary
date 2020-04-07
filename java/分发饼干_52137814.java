class Solution {
    public int findContentChildren(int[] g, int[] s) {
        if(g.length==0||s.length==0){
            return 0;
        }
        Arrays.sort(g);
        Arrays.sort(s);
        int ans = 0;
        int j=0;
        int i=0;
        while(true){
            if(g[i]<=s[j]){
                ans++;
                i++;
            }
            j++;
            if(j==s.length||i==g.length){
                break;
            }
        }
        return ans;
    }
}