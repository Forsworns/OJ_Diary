class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        vector<pair<int,int>> solutions(n); // first为第一步采取上一级的情况，second为第一步采取上两级的情况
        solutions[0].first = 1;
        solutions[0].second = 0;
        solutions[1].first = 1;
        solutions[1].second = 1; 
        for(int i=2;i<n;++i){
            solutions[i].first = solutions[i-1].first + solutions[i-1].second;
            solutions[i].second = solutions[i-2].first + solutions[i-2].second;
        }
        return solutions[n-1].first + solutions[n-1].second;
    }
};