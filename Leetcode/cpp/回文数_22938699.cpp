class Solution {
// 每次在对比首尾后在原数中减去这些数
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int MAXN = 10;
        vector<int> pows;
        bool ans = true, inNum = false;
        for(auto i=0;i<=MAXN;++i){
            pows.push_back(pow(10,i));
            if(x/pows[i]==0){
                MAXN = i-1;
                break; 
            }
        }
        for(auto i=MAXN;i>0;i-=2){
            int x1 = x/pows[i];
            x = x-x1*pows[i];
            int x2 = x%10;
            x = (x-x2)/10;
            if(x1!=x2){
                ans = false;
                break;
            }
        }
        return ans;
    }
};