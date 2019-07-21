class Solution {
// 之前使用set，只做了部分剪枝，有重复的情况。这里回溯
private:
    char l2u(const char &c){
        return c-'a'+'A';
    }
    char u2l(const char &c){
        return c-'A'+'a';
    }
    vector<string> ans;
    void permute(string S, const int &i){
        if(i>=S.length()){
            return;
        }
        permute(S,i+1);
        if(S[i]>='a'&&S[i]<='z'){ 
            S[i] = l2u(S[i]);
            ans.push_back(S);
            permute(S,i+1);
        }
        else if(S[i]>='A'&&S[i]<='Z'){
            S[i] = u2l(S[i]);
            ans.push_back(S);
            permute(S,i+1);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        ans.push_back(S);
        permute(S,0);
        return ans;
    }
};