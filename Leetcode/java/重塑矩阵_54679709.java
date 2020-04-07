class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(nums.length==0 || nums[0].length==0){
            return nums;
        }
        final int OR = nums.length, OC = nums[0].length;
        if(OR*OC!=r*c){
            return nums;
        } 
        int[][] ans = new int[r][c];
        int pos=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                ans[i][j] = nums[pos/OC][pos%OC];
                pos++;
            }
        }
        return ans;
    }
}