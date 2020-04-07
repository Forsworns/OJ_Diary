class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_set<long long> path; // 会出现循环，所以只看一个周期里的位置就行
        path.insert(0);
        int pos_x = 0,pos_y = 0;
        for(auto &c : command){
            if(c=='U'){
                pos_y++;
            }else{
                pos_x++;
            }
            path.insert(((long long)pos_x << 30) | pos_y);
        }
        
        int circle = min(x/pos_x,y/pos_y);
        if(path.count(((long long)(x-circle*pos_x) << 30) | (y-circle*pos_y)) == 0) return false;
        
        for(auto &o: obstacles){
            if(o.size() != 2) continue;
            if(o[0] > x || o[1] > y) continue;
            circle = min(o[0]/pos_x,o[1]/pos_y);
            if(path.count(((long long)(o[0]-circle*pos_x) << 30) | (o[1]-circle * pos_y))) return false;
        }
        return true;
    }
};