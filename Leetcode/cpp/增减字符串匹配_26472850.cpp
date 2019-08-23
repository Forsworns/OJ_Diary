class Solution {
public:
    vector<int> diStringMatch(string S) {
        const int L = S.length();
        vector<int> res(L+1);
        int inc = 0, dec = L;
        // 由递推关系，可以得知越先遇到D的越大，遇到I的会是最小的，于是遍历一次就可以了
        for(int i=0;i<=L;++i){
            if(S[i]=='I'){
                res[i] = inc++;
            }else{
                res[i] = dec--;
            }
        }
        return res;
    }
};