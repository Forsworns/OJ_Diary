class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        if(prices.size()==0) {
            return 0;
        }
        int minPrice = prices[0]; // 单另存放当前的最低价格
        int days = prices.size();
        int *maximum = new int[days+1](); // 考虑前i天的时候最大值
        for(int i=1;i<=days;++i){
            minPrice = min(minPrice,prices[i-1]);
            maximum[i] = max(maximum[i-1],prices[i-1]-minPrice);
        }
        return maximum[days];
    }
};