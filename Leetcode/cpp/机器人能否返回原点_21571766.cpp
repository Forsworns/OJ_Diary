class Solution {
public:
    bool judgeCircle(string moves) {
        int lrud[2] = {0};
        for(int i=0;i<moves.length();++i){
            if(moves[i]=='L'){
                lrud[0]++;
            }else if(moves[i]=='R'){
                lrud[0]--;
            }else if(moves[i]=='U'){
                lrud[1]++;
            }else{
                lrud[1]--;
            }
        }
        return lrud[0]==0 && lrud[1]==0;
    }
};