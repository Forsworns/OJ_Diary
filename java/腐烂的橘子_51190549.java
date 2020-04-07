class Solution {
    private static final int R[] = {1,-1,0,0};
    private static final int C[] = {0,0,1,-1};

    public int orangesRotting(int[][] grid) {
        int changeNum=0, time = 0;
        int r = grid.length, c = grid[0].length;
        int[][] old = new int[r][c];
        while(true) {
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    old[i][j] = grid[i][j];
                }
            }
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    if(old[i][j]==2){
                        for(int k=0;k<4;++k){
                            try {
                                if(old[i+R[k]][j+C[k]]==1){
                                    grid[i+R[k]][j+C[k]]=2;
                                    changeNum++;
                                }
                            } catch(ArrayIndexOutOfBoundsException e){}   
                        }
                        grid[i][j]=0;
                    }
                }
            }

            if(changeNum>0){
                time++;
                changeNum = 0;
            }else{
                for(int i=0;i<r;++i){
                    for(int j=0;j<c;++j){
                        if(grid[i][j]==1){
                            return -1;
                        }
                    }
                }
                return time;
            }
        } 
    }
}