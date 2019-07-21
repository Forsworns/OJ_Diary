class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int L = cost.size();
        /*if(L==0||L==1){
            return 0;
        }*/
        vector<int> sum(L+1);
        sum[0] = 0; // 在一层，二层的情况下均可直接到达
        sum[1] = 0;
        for(int i=2;i<=L;++i){
            sum[i] = min(sum[i-1]+cost[i-1],sum[i-2]+cost[i-2]); // 转化为往下一层或两层的子问题
        }
        return sum[L];
    }
};