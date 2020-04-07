class Solution {
    public int repeatedNTimes(int[] A) {
        Arrays.sort(A);
        if(A[A.length/2-1] == A[A.length/2] || A[A.length/2-1]== A[0]){
            return A[A.length/2-1];
        } else{
            return A[A.length/2];
        }
    }
}