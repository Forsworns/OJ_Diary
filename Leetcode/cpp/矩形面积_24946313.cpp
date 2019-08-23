class Solution {
// 减去重叠面积，其实为了不溢出可以先减去，再加上……没必要转long long
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (E >= C || G <= A || H <= B || F >= D) {
            return (long long int)((D-B)*(C-A))+(long long int)((H-F)*(G-E));
        }
        return (long long int)((D-B)*(C-A))+(long long int)((H-F)*(G-E))-(long long int)((min(C,G)-max(A,E))*(min(D,H)-max(B,F)));
    }
};