class Solution {
// 利用栈来记录当前出现的括号
public:
    bool isValid(string s) {
        stack<int> brackets;
        for(int i=0;i<s.length();++i){
            switch(s[i]){
                case '(':
                    brackets.push(0);
                    break;
                case ')':
                    if(!brackets.empty() && brackets.top()==0){
                        brackets.pop();
                    }else{
                        return false;
                    }
                    break;
                case '[':
                    brackets.push(1);
                    break;
                case ']':
                    if(!brackets.empty() && brackets.top()==1){
                        brackets.pop();
                    }else{
                        return false;
                    }
                    break;
                case '{':
                    brackets.push(2);
                    break;
                case '}':
                    if(!brackets.empty() && brackets.top()==2){
                        brackets.pop();
                    }else{
                        return false;
                    }
                    break;
            }
        }
        return brackets.empty();
    }
};