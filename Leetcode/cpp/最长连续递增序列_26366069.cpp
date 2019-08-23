class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int ans = 0, now =0;
        int last = 0;
        bool start = true;
        for(auto &x:nums){
            if(start || x>last){
                now++;
                last = x;
                start = false;
            }else{
                ans = max(ans,now);
                now = 1;
                last = x;
            }
        }
        return max(ans,now);
    }
};