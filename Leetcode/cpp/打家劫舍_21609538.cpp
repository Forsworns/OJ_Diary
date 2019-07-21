class Solution {
private:
	const int UNVISITED = -1;
public:
	int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
		if (nums.size() == 1) {
			return nums[0];
		}
		if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}
		int last = UNVISITED;// 最后一家的资产，如果是负数代表未打劫
		vector<int> sum(nums.size());// 前n家最大的
		sum[0] = nums[0];
        if(nums[0]>=nums[1]){
            sum[1] = nums[0];
            last = UNVISITED;
        }else{
            sum[1] = nums[1];
            last = nums[1];
        }
		for (int i = 2; i < nums.size(); ++i) {
			if (last == UNVISITED) { // 上一家没到过，那直接打劫下一家
				sum[i] = sum[i-1]+nums[i];
				last = nums[i];
			}
			else {
				if (nums[i]+sum[i - 2]<sum[i-1]) {
                    last = UNVISITED; //跳过新的一家
                    sum[i] = sum[i - 1];
				}
				else { // 下一家比上一家有钱
					sum[i] = sum[i - 2] + nums[i]; //直接调用i-2户的，不用再往前推导，因为之前的都是最优的了
					last = nums[i]; 
				}
			}
		}
		return sum[nums.size()-1];
	}
};