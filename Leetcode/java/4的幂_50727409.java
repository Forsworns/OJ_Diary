// 暴力破解
class Solution {
    public boolean isPowerOfFour(int num) {
        int temp = 1;
        Set<Integer> s = new HashSet<>();
        while(temp>0){
            s.add(temp);
            temp*=4;
        }
        if(s.contains(num)){
            return true;
        }else{
            return false;
        }
    }
}