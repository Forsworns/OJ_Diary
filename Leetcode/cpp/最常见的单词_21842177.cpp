class Solution {
private:
    map<string,int> dict; 
    void toLower(string &str){
        for(int i=0;i<str.length();i++){
            if(str[i]>='A'&&str[i]<='Z'){
                str[i] = str[i]-'A'+'a';
            }
        }
    }
    bool isChar(const char &c){
        return c>='a'&&c<='z';
    }
    void split(const string &s){
        string temp = "";
        for(int i=0;i<s.length();++i){
            if(isChar(s[i])){
                temp+=s[i];
            }else{
                if(temp.length()!=0){
                    if(dict.count(temp)==0){
                        dict.insert(make_pair(temp,1));
                    }else{
                        dict[temp]++;
                    }
                    temp = "";
                }
            }
        }
        if(temp.length()!=0){
            if(dict.count(temp)==0){
                dict.insert(make_pair(temp,1));
            }else{
                dict[temp]++;
            }
        }
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        toLower(paragraph);
        split(paragraph);
        set<string> banSet(banned.begin(),banned.end());
        string ans = "";
        int times = 0;
        for(map<string,int>::iterator it=dict.begin();it!=dict.end();++it){
            if(!banSet.count(it->first)){
                if(times<it->second){
                    times = it->second;
                    ans = it->first;
                }
            }    
        }
        return ans;
    }
};