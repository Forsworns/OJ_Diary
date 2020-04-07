class Solution {
    boolean[][] temp;
    private int countLive(int x, int y){
        int count = 0;
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(x+i>=0 && x+i<temp.length && y+j>=0 && y+j<temp[0].length && temp[x+i][y+j]){
                    count+=1;
                }
            }
        }
        if(temp[x][y]){
            count-=1;
        }
        return count;
    }

    public void gameOfLife(int[][] board) {
        if(board.length==0){
            return;
        }
        temp = new boolean[board.length][board[0].length];
        for(int i=0;i<board.length;++i){
            for(int j=0;j<board[0].length;++j){
                temp[i][j] = (board[i][j]==1);
            }
        }

        for(int i=0;i<board.length;++i){
            for(int j=0;j<board[0].length;++j){
                int count = countLive(i,j);
                if(count>3 && temp[i][j]){
                    board[i][j]=0;
                }
                else if(temp[i][j] && count<2){
                    board[i][j] = 0;
                }
                else if(!temp[i][j] && count==3){
                    board[i][j] = 1;
                }
            }
        }

    }
}