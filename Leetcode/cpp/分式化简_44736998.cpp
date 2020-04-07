class Solution {
// 整数部分不会影响分式的最简，不需要考虑化简
// 递归版
private:
    vector<int> ans{0,1};
public:
    vector<int> fraction(vector<int>& cont) {
        if(cont.size()==1){
            ans[0] = cont[0];
            return ans;
        }
        else if(cont.size()==2){
            ans[0] = cont[0]*cont[1]+1;
            ans[1] = cont[1];
            return ans;
        } else {
            int front = cont.front();
            cont.erase(cont.begin());
            ans = fraction(cont);
            int denominator = ans[0];
            ans[0] = front*ans[0] + ans[1]; // numerator
            ans[1] = denominator;
            return ans;
        }
    }
};