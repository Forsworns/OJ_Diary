class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int* ans = new int[N]();
        vector<vector<int>> edges(N);
        for(int i=0;i<paths.size();++i){
            edges[paths[i][0]-1].push_back(paths[i][1]-1);
            edges[paths[i][1]-1].push_back(paths[i][0]-1);
        }
    
        for(int i=0;i<N;++i){
            bool used[5] = {0}; // 0号颜色预留给没涂色 
            for(int j=0;j<edges[i].size();++j){
                used[ans[edges[i][j]]] = true;
            }
            for(int j=1;j<=4;++j){
                if(!used[j]){
                    ans[i] = j;
                    break; 
                }
            }
        }
        
        return vector<int>(ans,ans+N);
    }
};