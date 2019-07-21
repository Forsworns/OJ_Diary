class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        vector<pair<char,int>> chars;
        map<char,int> pos;
        
        for(int i=0;i<s.length();++i){
            if(pos.count(s[i])){
                chars[pos[s[i]]].second++;
            }else{
                pos.insert(make_pair(s[i],chars.size()));
                chars.push_back(make_pair(s[i],1));
            }
        }
        
        for(int i=0; i<chars.size();++i){
            if(chars[i].second==1){
                ans = s.find(chars[i].first);
                break;
            }
        }
        
        
        return ans;
    }
};