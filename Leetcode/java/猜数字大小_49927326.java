/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */
// 二分查找
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 0;
        int h = n;
        int g = l+(h-l)/2; // 非常关键……不然处理大数(l+h)会溢出
        int res = guess(g);
        while(res!=0){
            if(h==l+1){
                if(guess(l)==0){
                    return l;
                }else{
                    return h;
                }
            }
            if(res==-1){
                h = g;
            }else{
                l = g;
            }
            g = l+(h-l)/2;
            res = guess(g);
        }
        return g;
    }
}