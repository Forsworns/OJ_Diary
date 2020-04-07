import java.util.Arrays;

class Solution {
    public int countPrimes(int n) {
        if(n==0 || n==1){
            return 0;
        }
        boolean[] isPrim = new boolean[n];
        Arrays.fill(isPrim,true);
        int ans = 0;
        for(int i=2;i*i<n;i++){
            if(isPrim[i]){  
                for(int j=i*i;j<n;j+=i){
                    isPrim[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++){
            if(isPrim[i]){
                ans++;
            }    
        }
        return ans;
    }
}