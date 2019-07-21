class Solution {
private:
    bool isBlank(char a){
        return a==' ';
    }
public:
    int countSegments(string s) {
        int ans = 0;
        bool inWord = false;
        for(int i=0;i<s.length();++i){
            if(inWord && isBlank(s[i])){
                inWord = false;
            }else if(!inWord && !isBlank(s[i])){
                inWord = true;
                ans++;
            }
        }
        return ans;
    }
};