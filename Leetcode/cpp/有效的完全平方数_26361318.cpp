class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=0;
        for(;num>0;++i){
            num -= (2*i+1); 
        }
        return num==0;
    }
};