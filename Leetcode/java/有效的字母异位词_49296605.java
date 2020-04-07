// 只有小写字母，用数组做表就行，否则要用hashmap
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }
        int[] dict = new int[26];
        for(int i=0;i<s.length();++i){
            dict[s.charAt(i)-'a']++;
        }
        for(int i=0;i<t.length();++i){
            dict[t.charAt(i)-'a']--;
        }
        for(int i=0;i<dict.length;++i){
            if(dict[i]!=0){
                return false;
            }
        }
        return true;
    }
}