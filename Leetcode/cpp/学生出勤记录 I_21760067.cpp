class Solution {
public:
    bool checkRecord(string s) {
        int numA = 0;
        int numL = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='A'){
                numA++;
                if(numL<3){
                    numL = 0;   
                }
            }else if(s[i]=='L'){
                numL++;
            }else{
                if(numL<3){
                    numL = 0;   
                }
            }
        }
        return numA<=1 && numL<=2;
    }
};