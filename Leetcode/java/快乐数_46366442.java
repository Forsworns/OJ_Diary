import java.util.*;

class Solution {
    static final int[] DIGITS = {0,1,4,9,16,25,36,49,64,81};
    
    private int split_sum(int n){
        List<Integer> list = new ArrayList<>();
        while(n!=0){
            list.add(n%10);
            n = n/10;
        }
        Stream<Integer> stream = list.stream();
        int sum = stream.reduce(0, (acc, i) -> acc + DIGITS[i]);
        return sum;
    }

    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while(!set.contains(n)){
            int sum = split_sum(n);
            if(sum==1) {
                return true;
            }
            set.add(n);
            n = sum;
        }
        return false;
    }
}