class Solution {
// 这个是题解中O(n)的思路，比起之前提交的版本，它的缺点是不能知道三元组是什么（不过也没要求....
// 原理就是，不断更新三元组，尽管结果中的small可能已经被更小的值替换掉了，但是仍然可以知道三元组存在；而当big也被替换掉，是一个真正的新三元组
// 注意无论是哪种思路，序都是靠正向遍历就足够保证的
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX,big=INT_MAX;
        for(auto &x:nums){
            if(x<=small){
                small = x;
            }else if(x<=big){ // 注意必须取等，否则会把相等的数当作三元组
                big = x;  
            }else{
                return true;
            }
        }
        return false;
    }
};