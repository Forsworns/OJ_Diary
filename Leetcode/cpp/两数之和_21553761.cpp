class Solution {
private:
	int *index;
public:
	void quickSort(vector<int> &nums) {
		quickSort(nums, 0, nums.size() - 1);
	}
	void quickSort(vector<int> &nums, const int &left, const int &right) {
		if (left >= right) {
			return;
		}
		else {
			int l = left, r = right;
			int flag = nums[left];
			int flagIndex = index[left];
			while (l < r) {
				while (l<r && nums[r] >= flag) { 
					--r; 
				}
				if (l < r) { 
					nums[l] = nums[r]; 
					index[l] = index[r];
					++l;
				}
				while (l < r && nums[l] <= flag) { 
					++l;
				}
				if (l < r) { 
					nums[r] = nums[l]; 
					index[r] = index[l];
					--r;
				}
			}
			nums[l] = flag;
			index[l] = flagIndex;
			quickSort(nums, left, l - 1);
			quickSort(nums, l + 1, right);
			return;
		}
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		index = new int[nums.size()];
		for (int i = 0; i < nums.size();++i) {
			index[i] = i;
		}
		quickSort(nums);
		for (int i = 0; i < nums.size();++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					vector<int> ans;
					ans.push_back(index[i]);
					ans.push_back(index[j]);
					return ans;
				}
				else if (nums[i] + nums[j] > target) {
					break;
				}
			}
		}
		return vector<int>(2,0);
	}
};