class Solution {
    public int islandPerimeter(int[][] grid) {
        if(grid.length==0||grid[0].length==0){
            return 0;
        }
        int ans = 0;
        final int I = grid.length,J = grid[0].length;
        for(int i=0;i<I;++i){
            boolean flag = false;
            for(int j=0;j<J;++j){
                if(grid[i][j]==1){
                    if(!flag){
                        ans+=2;
                        flag = true;
                    }
                }else{
                    flag = false;
                }
            }
        }
        for(int j=0;j<J;++j){
            boolean flag = false;
            for(int i=0;i<I;++i){
                if(grid[i][j]==1){
                    if(!flag){
                        ans+=2;
                        flag = true;
                    }
                }else{
                    flag = false;
                }
            }
        }
        return ans;
    }
}