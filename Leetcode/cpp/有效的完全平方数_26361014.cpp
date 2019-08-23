class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        for(;i*i<num;++i){
            if(num-i*i<2*i+1){ // 防止溢出，判断整数是否是在i^2到(i+1)^2间
                return false;
            }
        }
        return i*i == num;
    }
};