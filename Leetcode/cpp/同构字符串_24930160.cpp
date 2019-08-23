class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> isomap;
        unordered_set<char> isoset;
        for(auto i=0;i<min(s.length(),t.length());++i){
            if(isomap.find(s[i])!=isomap.end()){
                if(isomap[s[i]]!=t[i]){
                    return false;
                }
            }else{
                if(isoset.find(t[i])==isoset.end()){
                    isomap.insert(make_pair(s[i],t[i]));
                    isoset.insert(t[i]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};