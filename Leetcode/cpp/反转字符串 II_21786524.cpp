class Solution {
private:
    string reverse(const string &s){
        string res = s;
        for(int i=0;i<s.length();++i){
            res[i] = s[s.length()-1-i];
        }
        return res;
    }
public:
    string reverseStr(string s, int k) {
        string ans = "";
        int i=0;
        for(;i<s.length()/(2*k);++i){
            ans+=reverse(s.substr(i*2*k,k));
            ans+=s.substr(i*2*k+k,k);
        }
        if(s.length()-i*2*k<k){
            ans+=reverse(s.substr(i*2*k));
        }else{
            ans+=reverse(s.substr(i*2*k,k));
            ans+=s.substr(i*2*k+k);
        }
        return ans;
    }
};