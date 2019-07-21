class Solution {
private:
    string codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int getIdx(char c){
        return c-'a';
    }
    
    string transform(string s){
        string t = "";
        for(int i=0;i<s.length();++i){
            t+=codes[getIdx(s[i])];
        }
        return t;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> transformed;
        for(int i=0;i<words.size();++i){
            string t = "";
            t = transform(words[i]);
            if(transformed.count(t)==0){
                transformed.insert(t);
            }
        }     
        return transformed.size();
    }
};