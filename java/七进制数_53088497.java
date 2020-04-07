import java.lang.StringBuilder;
class Solution {
    public String convertToBase7(int num) {
        if(num==0){
            return "0";
        }
        String ans="";
        boolean isNeg = num<0;
        num = Math.abs(num);
        while(num>0){
            ans+=String.valueOf(num%7);
            num/=7;
        }
        if(isNeg){
            return "-"+new StringBuilder(ans).reverse().toString();
        }else{
            return new StringBuilder(ans).reverse().toString();
        }
    }
}