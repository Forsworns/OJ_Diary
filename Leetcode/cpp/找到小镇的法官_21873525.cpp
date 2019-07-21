class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        bool** edges = new bool*[N]; 
        for(int i=0;i<N;++i){
            edges[i] = new bool[N]();
        }

        for(int i=0;i<trust.size();++i){
            edges[trust[i][0]-1][trust[i][1]-1] = true;
        }
        
        for(int i=0;i<N;++i){
            bool isLawer = true;
            for(int j=0;j<N;++j){ // 检验一行，他信任别人
                if(edges[i][j]){
                    isLawer = false;
                }
            }
            for(int j=0;j<N;++j){ // 检验一列，别人信任他
                if(i!=j && !edges[j][i]){
                    isLawer = false;
                }
            }
            if(isLawer){
               return i+1; 
            }
        }
        
        return -1;
    }
};