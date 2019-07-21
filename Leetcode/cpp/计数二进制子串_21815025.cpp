class Solution {
// 补充成#0#0#1#1#1#这样的，然后ans是#各个位置的最长01/0011/000111...半径之和
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        const int L = s.length();
        string ss = "#";
        // 先补充#
        for(int i=0;i<L;++i){
            ss += s[i];
            ss += "#";
        }
        const int LL = ss.length();
        int *r = new int[LL](); // 用来记录#各个位置的回文串最大半径
        for(int i=2;i<LL-2;i+=2){
            int j=1;
            if(ss[i-j]!=ss[i+j]){
                j+=2;
                r[i]++;
                while(i-j>0 && i+j<LL && ss[i-j]==ss[i-j+2] && ss[i+j] == ss[i+j-2]){
                    r[i]++;
                    j+=2;
                } 
            }
            ans+=r[i];
        }
        return ans;
    }
};