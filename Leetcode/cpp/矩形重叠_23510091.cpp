class Solution {
// 计算可能出现的重合区域的左下和右上，看是否是合法矩形
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int overlapXLD = max(rec1[0],rec2[0]);
        int overlapYLD = max(rec1[1],rec2[1]);
        int overlapXRU = min(rec1[2],rec2[2]);
        int overlapYRU = min(rec1[3],rec2[3]);
        return overlapXLD<overlapXRU && overlapYLD<overlapYRU; 
    }
};