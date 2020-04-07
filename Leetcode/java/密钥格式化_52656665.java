class Solution {
    public String licenseKeyFormatting(String S, int K) {
        int len=0;
        char[] s = new char[S.length()];
        for(int i=0;i<S.length();++i){
            if(S.charAt(i)!='-'){
                if(S.charAt(i)>='a' && S.charAt(i)<='z'){
                    s[len] = Character.toUpperCase(S.charAt(i));
                }else{
                    s[len] = S.charAt(i);
                }
                len++;
            }
        }
        if(len==0){
            return "";
        }
        int start = len % K;
        String ans = "";
        for(int i=0;i<start;++i){
            ans += s[i];
        }
        if(len==start){
            return ans;
        }
        else if(start!=0){
            ans+='-'; 
        }
        ans += s[start];
        
        for(int i=start+1;i<len;++i){
            if((i-start) % K == 0){
                ans += '-';
            }
            ans += s[i];
        }
        return ans;
    }
}