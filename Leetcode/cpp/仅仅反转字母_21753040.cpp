class Solution {
private:
    inline bool isChar(char input){
        return (input<='z'&&input>='a')||(input<='Z'&&input>='A');
    }
    void reverse(string &input){
        char temp;
        for(int i=0;i<input.length()/2;++i){
            temp = input[i];
            input[i] = input[input.length()-1-i];
            input[input.length()-1-i] = temp;
        }
    }
public:
    string reverseOnlyLetters(string S) {
        string orig = "";
        string ans = "";
        vector<pair<int,char>> delimiter;
        for(int i=0;i<S.length();++i){
            if(isChar(S[i])){
                orig+=S[i];
            }else{
                delimiter.push_back(make_pair(i-1-delimiter.size(),S[i])); // 这里delimiter的first是记录的在字符串的第几个字符之后
            }
        }
        reverse(orig);
        int vecIdx = 0;
        for(int i = vecIdx; i < delimiter.size(); ++i){ // delimiter可能出现在字符串前
            if(delimiter[i].first==-1){
                ans+=delimiter[i].second;
                vecIdx++;
            }else{
                break;
            }
        }
        for(int i=0;i<orig.length();++i){
            ans += orig[i];
            for(int j = vecIdx; j < delimiter.size(); ++j){ // 之前的delimiter不可能是该位置的，直接舍弃
                if(vecIdx<delimiter.size() && delimiter[vecIdx].first==i){
                    ans += delimiter[vecIdx].second;    
                    vecIdx++;
                }else{
                    break;
                }
            }
            
        }
        for(int i = vecIdx; i < delimiter.size(); ++i){ // 别忘了最后还有可能没有读完delimiter
            ans+=delimiter[i].second;
        }
        return ans;
    }
};