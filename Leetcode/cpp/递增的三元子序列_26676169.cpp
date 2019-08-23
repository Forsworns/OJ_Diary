class Solution {
// 搞一个vector存pair，读到当前位置能拿到的递增pair，没有的就存INT_MIN <limits.h>(特例是测试用例里有INT_MIN，但是INT_MIN是不可能出现在pair.second上的，INT_MAX也是，所以这个无所谓)
// 最坏情况是O(n^2)，还是比O(n^3)的遍历要好的
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<pair<int,int>> increasingPair;
        for(auto &x:nums){
            bool bSmallest = true;
            for(auto &item:increasingPair){
                if(item.second!=INT_MIN && x>item.second){ // 比任意一个pair.second大，构成一个triple了
                    return true;
                }else if(x>item.first){ // 它在nums中是在一个pair.second的后面，又比它小，所以可以替换它;或是对于
                    item.second = x;
                    bSmallest = false;
                }
            }
            // 比之前的都小，新建一个pair
            if(bSmallest){
                increasingPair.emplace_back(x,INT_MIN);
            }
        }
        return false;
    }
};