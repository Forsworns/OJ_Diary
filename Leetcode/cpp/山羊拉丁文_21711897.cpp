class Solution {
private:
    const char VOWEL[10] = {'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char c){
        for(int i=0;i<10;++i){
            if(c==VOWEL[i]){
                return true;
            }
        }
        return false;
    }
    vector<string> split(const string &input, const char &delimiter){
        vector<string> ans;
        string temp = "";
        for(int i=0;i<input.length();++i){
            if(input[i]==delimiter){
                ans.push_back(temp);    
                temp = "";
            }else{
                temp+=input[i];   
            }
        }
        ans.push_back(temp);
        return ans;
    }
public:
    string toGoatLatin(string S) {
        string answer = "";
        vector<string> splited = split(S, ' ');
        for(int i=0; i<splited.size(); ++i){
            string word = splited[i];
            if(isVowel(word[0])){
                word += "ma";
            }else{
                word += word[0];
                word = word.substr(1);
                word += "ma";
            }
            for(int j=0;j<=i;++j){
                word+="a";
            }
            answer += word;
            answer += " ";
        }
        return answer.substr(0,answer.length()-1);
    }
};