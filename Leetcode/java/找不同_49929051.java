class Solution {
    public char findTheDifference(String s, String t) {
        // 记得用异或！
        char ans = 0;
        for(int i=0;i<s.length();++i){
            ans ^= s.charAt(i);
        }
        for(int i=0;i<t.length();++i){
            ans ^= t.charAt(i);
        }
        return ans;
    }
}