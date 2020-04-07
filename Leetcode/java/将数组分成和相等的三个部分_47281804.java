// 用stream反而会降低效率？可能主要是初始化的时候
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i=0;i<A.length;++i){
            sum += A[i];
        }
        if(sum % 3 != 0){
            return false;
        }
        int current = 0;
        int count = 0;
        boolean ans = false;
        for(int a : A){
            current += a;
            if(current == sum / 3){
                count++;
                current = 0;
            }
        }
        return count == 3;
    }
}