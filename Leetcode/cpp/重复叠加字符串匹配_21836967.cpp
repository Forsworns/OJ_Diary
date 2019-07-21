class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int times = ceil(B.length()/float(A.length()));
        string s = "";
        for(int i=0;i<times;i++){
            s += A;
        }
        if(s.find(B)!=string::npos){
            return times;
        }
        
        s = "";
        for(int i=0;i<times+1;i++){
            s += A;
        }
        if(s.find(B)!=string::npos){
            return times+1;
        }
        return -1;
    }
};