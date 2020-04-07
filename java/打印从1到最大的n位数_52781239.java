class Solution {
    public int[] printNumbers(int n) {
        int upper_bound = (int) Math.pow(10,n) - 1;
        int[] ans = new int[upper_bound];
        for(int i=0;i<upper_bound;++i){
            ans[i] = i+1;
        }
        return ans;
    }
}