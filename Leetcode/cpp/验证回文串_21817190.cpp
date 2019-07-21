class Solution {
private:
    string removeBlank(const string &s){
        string res = "";
        for(int i=0;i<s.length();++i){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]<='9'&&s[i]>='0')){
                res+=s[i];
            }
        }
        return res;
    }
    void toLower(string &s){
        for(int i=0;i<s.length();++i){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] = s[i]-'A'+'a';
            }
        }
    }
public:
    bool isPalindrome(string s) {
        s = removeBlank(s);
        if(s.length()==0){
            return true;
        }
        toLower(s);
        for(int i=0;i<s.length()/2;++i){
            if(s[i]!=s[s.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};