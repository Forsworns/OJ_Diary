class Solution {
private:
    char toLower(char input){
        if(input>='A'&&input<='Z'){
            input = input - 'A' + 'a';
        }
        return input;
    }
public:
    string toLowerCase(string str) {
        string answer = "";
        for(int i=0;i<str.length();++i){
            answer += toLower(str[i]);
        }
        return answer;
    }
};