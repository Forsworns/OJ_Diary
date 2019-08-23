class Solution {
public:
    vector<int> diStringMatch(string S) {
        const int L = S.length();
        vector<int> res(L+1);
        int now = 0;
        // 先正序按I的位置增大
        for(int i=0;i<L;++i){
            if(S[i]=='I'){
                res[i] = now;
                now++;   
            }
        }
        res[L] = now; // res[L]一定是num
        now++;
        // 再反序按D的位置增大
        for(int i=L-1;i>=0;--i){
            if(S[i]=='D'){
                res[i] = now;
                now++;   
            }
        }
        return res;
    }
};