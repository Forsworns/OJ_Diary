class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length()){
            return false;
        }
        if(A==B){
            set<char> encounter;
            for(int i=0;i<A.length();++i){
                if(encounter.count(A[i])){
                    return true;
                }else{
                    encounter.insert(A[i]);
                }
            }
            return false;
        }
        int diff = 0;
        char c1,c2;
        for(int i=0;i<A.length();++i){
            if(A[i]!=B[i]){
                if(diff==0){
                    diff++; 
                    c1 = A[i];
                    c2 = B[i];
                }
                else if(diff==1){
                    if(c2==A[i]&&c1==B[i]){
                        diff++;
                    }else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return diff==0 || diff==2;
    }
};