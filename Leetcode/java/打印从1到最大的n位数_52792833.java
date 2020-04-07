// 大数加法，逆序计算，存储时翻转一下
class Solution {
    StringBuilder sb;
    int idx = 0;
    public boolean increment(int n){
        boolean carry=false;
        for(int i=0;i<sb.length();++i){
            if(carry || i==0){
                if(sb.charAt(i)=='9'){
                    sb.setCharAt(i,'0');
                    carry = true;
                }else{
                    sb.setCharAt(i,(char) (sb.charAt(i)+1));
                    carry = false;
                }
            }else{
                break; // no addition on last idx, no need to compute any more
            }
        }
        if(carry){
            sb.append("1");
        }
        return sb.length()<=n; // overflow!
    }

    public void save(int ans[]){
        ans[idx] = Integer.parseInt(sb.reverse().toString());
        sb.reverse();
    }

    public int[] printNumbers(int n) {
        int[] ans = new int[(int) Math.pow(10,n) - 1];
        sb = new StringBuilder("0");
        while(increment(n)){
            save(ans);
            idx++;
        }
        return ans;
    }
}