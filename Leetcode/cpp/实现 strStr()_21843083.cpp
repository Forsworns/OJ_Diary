class Solution {
// 暴力匹配
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        for(int i=0;i<haystack.length();++i){
            bool found = true;
            for(int j=0;j<needle.length();++j){
                if(i+j<haystack.length()){
                    if(haystack[i+j]!=needle[j]){
                        found = false;
                        break;
                    }
                }else{
                    return -1;
                }
            }
            if(found){
                return i;
            }
        }
        return -1;
    }
};