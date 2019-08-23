// 就是个堆栈题，"("和")"分别对应出入栈
// 既然之前都用counter给栈命名了……为啥没想到直接搞一个counter就行了
// 而且就地处理，没必要把位置再存一遍
class Solution {
public:
    string removeOuterParentheses(string S) {
        int counter = 0;
        string ans = "";
        for(int i=0;i<S.length();++i){
            if(counter==0){
                counter++;
                continue;    
            }else{
                if(S[i]=='('){
                    ans+=S[i];
                    counter++;
                }else{
                    counter--;
                    if(counter!=0){
                        ans+=S[i];
                    }
                }   
                
            }
        }
        return ans;
    }
};