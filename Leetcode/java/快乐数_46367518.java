import java.util.*;

class Solution {
    static final int[] DIGITS = {0,1,4,9,16,25,36,49,64,81};
    
    private int split_sum(int n){
        int sum = 0;
        while(n!=0){
            sum += DIGITS[n%10];
            n = n/10;
        }
        return sum;
    }

    public boolean isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = split_sum(slow);
            fast = split_sum(fast);
            fast = split_sum(fast);
        } while(slow!=fast);
        return slow==1;
    }
}