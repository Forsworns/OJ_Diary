class Solution {
    public int[][] imageSmoother(int[][] M) {
        final int I = M.length;
        final int J = M[0].length;
        int[][] N = new int[I][J];
        for(int i = 0; i<I;++i){
            for(int j=0;j<J;++j){
                int counter = 0;
                for(int k=-1;k<=1;++k){
                    for(int l=-1;l<=1;++l){
                        if(i+k>=0&&i+k<I&&j+l>=0&&j+l<J){
                            N[i][j] += M[i+k][j+l];
                            counter++;
                        }
                    }
                }
                N[i][j] /= counter;
            }
        }
        return N;
    }
}