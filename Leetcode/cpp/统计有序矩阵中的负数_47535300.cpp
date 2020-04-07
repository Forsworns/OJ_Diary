// 从右上角开始遍历
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int i = 0, j = c-1;
        int ans = 0;
        int temp = 0;
        while(true){
            if(i>=r||j<0){
                break;
            }
            if(grid[i][j] >= 0){
                ans+=c-j-1;
                i++;
            }else{
                j--;
            }
        }
        if(i<r){
            ans+=c*(r-i);
        }
        return ans;
    }
};