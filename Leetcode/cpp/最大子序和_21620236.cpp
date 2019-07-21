class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int L = nums.size();
        int sum = 0;
        int maxSum = nums[0];
        for(int i=0;i<L;++i){
            if(sum+nums[i]<0){
                sum = 0;
                maxSum = max(nums[i],maxSum);
            }else{
                sum+=nums[i];
                maxSum = max(sum,maxSum);
            }
        }
        return maxSum;
    }
};