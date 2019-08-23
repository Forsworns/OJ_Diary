#define DIV 60
class Solution {
// 朴素思路当然是n^2遍历
// O(n)方法的空间复杂度高：遍历一次求余，按余数计数，再遍历余数一次对应求积
// 但是上面这个思路是可以优化的，因为一对只需要计数一次，所以在遍历time时直接累加就行了
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int residue[DIV] = {0};
        for(auto &x:time){
            ans+=residue[(DIV-x%DIV)%DIV];
            residue[x%DIV]++;
        }
        return ans;
    }
};