class Solution {
private:
    char l2u(const char &c){
        return c-'a'+'A';
    }
    char u2l(const char &c){
        return c-'A'+'a';
    }
    set<string> ans;
    void permute(string S, const int &i){
        if(i>=S.length()){
            return;
        }
        permute(S,i+1);
        if(S[i]>='a'&&S[i]<='z'){ 
            ans.insert(S);
            S[i] = l2u(S[i]);
            ans.insert(S);
            permute(S,i+1);
        }
        else if(S[i]>='A'&&S[i]<='Z'){
            ans.insert(S);
            S[i] = u2l(S[i]);
            ans.insert(S);
            permute(S,i+1);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        permute(S,0);
        vector<string> realAns(ans.begin(),ans.end());
        if(ans.size()==0){ // S为纯数字
            realAns.push_back(S);
        }
        return realAns;
    }
};