// 二分法
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        // int row = matrix.length;
        if(matrix.length==0){
            return false;
        }
        int col = matrix[0].length;
        try{
            int i = 0;
            int j = col-1;
            while(true){
                if(matrix[i][j]<target){
                    i++;
                }else if(matrix[i][j]>target){
                    j--;
                }else{
                    return true;
                }
            }
        } catch(IndexOutOfBoundsException e) {
            return false;
        }
    }
}