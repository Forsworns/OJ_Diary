class Solution {
    // 做出来111111，然后取N的异或或是差都可以
    public int bitwiseComplement(int N) {
        if(N==0){
            return 1;
        }
        long mask=1;
        while(mask<=N){
            mask = mask<<1;
        }
        mask = mask-1; // 111111
        return (int) (N^mask);
    }
}