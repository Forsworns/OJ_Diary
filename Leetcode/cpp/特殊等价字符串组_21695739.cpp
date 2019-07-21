class Solution {
public:
    // 将奇偶idx拆开
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string,string>> words;
        for(int i=0;i<A.size();++i){
            string temp1 = "", temp2 = "";
            for(int j=0;j<A[i].length();++j){
                if(j%2){ // 奇
                    temp1 += A[i][j];     
                }else{ // 偶
                    temp2 += A[i][j];
                }
            }
            sort(temp1.begin(),temp1.end());
            sort(temp2.begin(),temp2.end());
            words.insert(make_pair(temp1,temp2));
        }
        return words.size();
    }
};