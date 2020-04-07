class Solution {
    public int largestPerimeter(int[] A) {
        int ans = 0;
        Arrays.sort(A);
        for(int i=A.length-1;i>=2;--i){
            if(A[i]<A[i-1]+A[i-2]){
                ans = A[i]+A[i-1]+A[i-2];
                break;
            }
        }
        return ans;
    }
}