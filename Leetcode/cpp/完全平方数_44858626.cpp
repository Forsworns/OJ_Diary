class Solution {
// 直接dp是O(n^2)，超时了
// 因为新的数，一定是由平方数加上另一个数构成的，可以减少讨论的情况
private:
    bool isSquare(int n) {
        return int(sqrt(n))*int(sqrt(n)) == n;
    }
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<int> res(n,1); 
        for(int i=0;i<n;++i){
            if(isSquare(i+1)){
                res[i] = 1;
                squares.push_back(i);
            }else{
                int min_num = n;
                for(auto &s:squares){
                    min_num = min(min_num,res[s]+res[i-s-1]);
                }
                res[i] = min_num;
            }
        }
        return res[n-1];
    }
};