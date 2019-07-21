class Solution {
// 改进方法，使用双指针思路。之前是直接算完排序
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        int pos1=-1,pos2=0;
        
        for(int i=0;i<A.size()-1;++i){
            if(A[i]<0&&A[i+1]>=0){
                pos1 = i;
                pos2 = i+1;
            }
            A[i] = A[i]*A[i];  
        }
        A[A.size()-1] = A[A.size()-1]*A[A.size()-1];
        
        while(pos1>=0 && pos2<A.size()){
            if(A[pos1]>A[pos2]){
                ans.push_back(A[pos2]);
                pos2++;
            }else{
                ans.push_back(A[pos1]);
                pos1--;
            }
        }
        while(pos1>=0){ // 类似归并时不必具体考虑是哪个，只要不满足跳过就好了
            ans.push_back(A[pos1]);
            pos1--;
        }
        while(pos2<A.size()){
            ans.push_back(A[pos2]);
            pos2++;
        }
        return ans;    
    }
};