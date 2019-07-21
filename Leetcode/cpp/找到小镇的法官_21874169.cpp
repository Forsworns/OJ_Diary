class Solution {
// 之前遍历边集去做，浪费了时间。这里计算入度和出度
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1){
            return 1;
        }
        int** degree = new int*[N]; 
        for(int i=0;i<N;++i){
            degree[i] = new int[N]();
        }

        for(int i=0;i<trust.size();++i){
            degree[trust[i][0]-1][0] +=1; // 出度
            degree[trust[i][1]-1][1] +=1; // 入度
        }
        
        for(int i=0;i<N;++i){
            if(degree[i][0]==0 && degree[i][1]==N-1){
               return i+1; 
            }
        }
        
        return -1;
    }
};