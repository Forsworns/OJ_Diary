class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool character = false;
        for(int i=s.length()-1;i>=0;--i){
            if(character){
                if(s[i]!=' '){
                    ans++;
                }else{
                    break;
                }
            }else{
                if(s[i]!=' '){
                    ans++;
                    character = true;
                }
            }
        }
        return ans;
    }
};