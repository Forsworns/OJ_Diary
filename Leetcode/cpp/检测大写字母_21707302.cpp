class Solution {
private:
    bool isUpper(char c){
        return c>='A' && c<='Z';
    }
public:
    bool detectCapitalUse(string word) {
        if(word.length()<=1){
            return true;
        }
        if(isUpper(word[0])&&isUpper(word[1])){
            for(int i=2;i<word.length();++i){
                if(!isUpper(word[i])){
                    return false;
                }
            }  
        }else{
            for(int i=1;i<word.length();++i){
                if(isUpper(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};