class Solution {
    // 做出来111111，然后取num的异或或是差都可以
    public int findComplement(int num) {
        long mask=1;
        while(mask<=num){
            mask = mask<<1;
        }
        mask = mask-1; // 111111
        return (int) (num^mask);
    }
}