class Solution {
private:
    bool is_obstacle(vector<vector<int>>& obstacles, int x,int y){
        for(int t=0;;++t){
            if(obstacles.size()==0){
                return false;
            }else{
                //cout<<t; // after sorted, most of the cases can be verified one time 
                if(x==obstacles[0][0] && y==obstacles[0][1]){
                    return true;
                }else if(x>obstacles[0][0] || y>obstacles[0][1]) {
                    obstacles.erase(obstacles.begin());
                }else{
                    return false;
                }
            }
        }
    }
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        sort(obstacles.begin(), obstacles.end(), [] (auto o1,auto o2){return o1[0]<o2[0] || (o1[0]==o2[0] && o1[1]<o2[1]); });
        int len = command.size();
        int pos_x = 0, pos_y = 0;
        for(int i=0;;++i){
            char cmd = command[i%len];
            switch(cmd) {
                case 'U': pos_y++; break;
                case 'R': pos_x++; break;
            }
            
            if(pos_x == x && pos_y == y){
                return true;
            } 
            else if(is_obstacle(obstacles, pos_x, pos_y)){
                return false;
            } 
            else if(pos_x > x || pos_y > y){
                return false;
            }
            
        }
    }
};