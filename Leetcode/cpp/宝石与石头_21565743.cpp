class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int answer = 0;
        for(int k=0;k<S.length();++k){
            for(int i=0;i<J.length();++i){
                if(S[k]==J[i]){
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
};