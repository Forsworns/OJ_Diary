class Solution {
    public int fib(int N) {
        if(N==0){
            return 0;
        }
        if(N==1){
            return 1;
        }
        int[] cached = new int[N+1];    
        cached[0]=0;
        cached[1]=1;
        for(int i=2;i<=N;++i){
            cached[i]=cached[i-1]+cached[i-2];
        }
        return cached[N];
    }
}