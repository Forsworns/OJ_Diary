// 就是个堆栈题，"("和")"分别对应出入栈
class Solution {
public:
    string removeOuterParentheses(string S) {
        unordered_set<int> pos;
        stack<bool> counter;
        for(int i=0;i<S.length();++i){
            if(counter.empty()){
                pos.insert(i);
            }
            if(S[i]=='('){
                counter.push(true);
            }else{
                counter.pop();
                if(counter.empty()){
                    pos.insert(i);
                }
            }
        }
        string ans = "";
        for(int i=0;i<S.length();++i){
            if(pos.find(i)==pos.end()){
                ans+=S[i];
            }
        }
        return ans;
    }
};