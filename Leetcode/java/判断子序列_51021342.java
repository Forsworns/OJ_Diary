// 如果是连续的子序列是用KMP算法
// 本题中子序列可以是断开的，所以只需要遍历一次就行了，对比时贪心匹配
// 用toCharArray转换成char 数组会比用charAt快？
class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length()==0){
            return true;
        }
        int sl = s.length(), tl = t.length();
        if(tl<sl){
            return false;
        }

        char[] sc = s.toCharArray(), tc = t.toCharArray();
        int j = 0;
        for(int i=0;i<tl;++i){
            if(tc[i]==sc[j]){
                j++;
            }
            if(j==sl){
                return true;
            }
        }
        return false;
    }
}