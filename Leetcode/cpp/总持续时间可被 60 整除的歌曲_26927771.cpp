#define DIV 60
class Solution {
// 朴素思路当然是n^2遍历
// O(n)方法的空间复杂度高：遍历一次求余，按余数计数，再遍历余数一次对应求积    
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int residue[DIV] = {0};
        for(auto &x:time){
            residue[x%DIV]++;
        }
        for(int i=1;i<DIV/2;++i){
            if(residue[i]*residue[DIV-i]){
            }
            ans += residue[i]*residue[DIV-i];
        }
        ans += (residue[0]-1)*residue[0]/2; 
        if(DIV%2==0){
            ans += (residue[DIV/2]-1)*residue[DIV/2]/2; // DIV为60时，对于30分要排除重复的
        }
        return ans;
    }
};