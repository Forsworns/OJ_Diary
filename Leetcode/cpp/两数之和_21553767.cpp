class Solution {
private:
	map<int, int> index;
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size();++i) {
			index.insert(pair<int,int>(nums[i],i));
		}
		for (int i = 0; i < nums.size();++i) {
			int toFind = target - nums[i];
			if (index.find(toFind)!=index.end() && index.find(toFind)->second!=i) {
				vector<int> ans;
				ans.push_back(i);
				ans.push_back(index.find(toFind)->second);
				return ans;
			}
		}
        return vector<int>(2,0);
	}
};