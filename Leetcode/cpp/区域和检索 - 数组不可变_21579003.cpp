class NumArray {
private:
    vector<int> sum; // 直接存储从0项到前i项的和
public:
    NumArray(vector<int>& nums) {
        int temp = 0;
        for(int i=0;i<nums.size();++i){
            sum.push_back(temp);
            temp+=nums[i];
        }
        sum.push_back(temp);
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */