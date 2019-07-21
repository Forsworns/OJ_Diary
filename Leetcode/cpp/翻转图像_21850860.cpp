class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        const int L = A.size();
        for(int i=0;i<L;++i){
            for(int j = 0;j<L/2;++j){
                int temp = A[i][j];
                A[i][j] = A[i][L-1-j];
                A[i][L-1-j] = temp;
            }
            for(int j = 0;j<L;++j){
                A[i][j] = !A[i][j];
            }
        }
        return A;
    }
};