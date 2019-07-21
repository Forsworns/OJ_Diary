class Solution {
private:
    string reverse(string input){
        char temp;
        const int L = input.length();
        for(int i=0;i<L/2;++i){ // 或(L-1)/2.0
            temp = input[i];
            input[i] = input[L-1-i];
            input[L-1-i] = temp;
        }
        return input;
    }    
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        for(int i=0;i<s.length();++i){
            if(s[i]==' '){
                words.push_back(temp);
                temp = "";
            }else{
                temp += s[i];   
            } 
        }
        words.push_back(temp);
        string answer = "";
        for(vector<string>::iterator it=words.begin();it<words.end();++it){
            answer += reverse(*it);
            answer += " ";
        }
        return answer.substr(0,answer.length()-1);
    }
};