// 由于给的状态是int，不用开辟额外空间，新增状态用来记录在变换之前的状态就好了
class Solution {
    final int D=0, L=1, LD=2,DL=3; //Death, Live
    private int countLive(int[][] board, int x, int y){
        int count = 0;
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(x+i>=0 && x+i<board.length && y+j>=0 && y+j<board[0].length && (board[x+i][y+j]==L || board[x+i][y+j]==LD)){
                    count+=1;
                }
            }
        }
        if(board[x][y]==L){
            count-=1;
        }
        return count;
    }

    public void gameOfLife(int[][] board) {
        if(board.length==0){
            return;
        }

        for(int i=0;i<board.length;++i){
            for(int j=0;j<board[0].length;++j){
                int count = countLive(board,i,j);
                if(count>3 && board[i][j]==L){
                    board[i][j]=LD;
                }
                else if(board[i][j]==L && count<2){
                    board[i][j] = LD;
                }
                else if(board[i][j]==D && count==3){
                    board[i][j] = DL;
                }
            }
        }

        for(int i=0;i<board.length;++i){
            for(int j=0;j<board[0].length;++j){
                if(board[i][j]==LD){
                    board[i][j] = D;
                }else if(board[i][j]==DL){
                    board[i][j] = L;
                }
            }
        }

    }
}