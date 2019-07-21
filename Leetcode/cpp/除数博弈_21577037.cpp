class Solution {
private:
    vector<int> findFactors(int input){
        vector<int> factors;
        for(int i=1;i<sqrt(input);++i){
            if(input%i==0){ // 是因子
                factors.push_back(i);
            }
        }
        return factors;
    }
public:
    bool divisorGame(int N) {
        bool dp[1005] = {0};
        for(int state = 2; state<=N; ++state){
            vector<int> factors = findFactors(state);
            for(int i=0;i<factors.size();++i){
                if(dp[state-factors[i]]==false){ // 选完数字后，下一手对手必输的情况
                    dp[state] = true; // 那么他必赢
                    break;
                }
            }
        }    
        return dp[N];
    }
};