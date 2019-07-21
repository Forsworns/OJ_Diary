class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string ans = "";
        int len = 1<<31-1;
        for(int i=0;i<strs.size();++i){
            len = min(int(strs[i].length()),len);
        }
        for(int i=0;i<len;++i){
            bool flag = false;
            char pattern = strs[0][i];
            for(int j=1;j<strs.size();++j){
                if(strs[j][i]!=pattern){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }else{
                ans+=pattern;
            }
        }
        return ans;
    }
};