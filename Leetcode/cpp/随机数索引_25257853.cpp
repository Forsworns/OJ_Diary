class Solution {
	// 思路是用链表的数组记录位置（类似图的邻接表形式）
	// 然后每次pick后将双向链表首部元素替换到链表末尾，模拟等概率产生
    // 之前只考虑了正整数，而且用vector的话空间消耗太大了
	// 另一个思路或许可以把0-1的random映射到pos数目随机取一个？
private:
	struct Node {
		Node *next;
		int val;
		Node() {
			next = nullptr;
			val = -1;
		}
		Node(int v) {
			next = nullptr;
			val = v;
		}
	};
	unordered_map<int,Node*> indices;
public:
	Solution(vector<int>& nums) {
        for(auto &x:nums){
            if(indices.find(x)==indices.end()){
                indices.insert(make_pair(x,new Node()));
            }
        } // 只是为了后面代码最小改动，所以这里这么写
        
		for (auto i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			auto node = indices[num];
			while (node->next != nullptr) {
				node = node->next;
			}
			node->next = new Node(i);
		}

	}

	int pick(int target) {
		int ans = indices[target]->next->val;
		auto node = indices[target]->next;
		indices[target]->next = node->next;
		node->next = nullptr;
		auto it = indices[target];
		while (it->next != nullptr) {
			it = it->next;
		}
		it->next = node;
		return ans;
	}
};
