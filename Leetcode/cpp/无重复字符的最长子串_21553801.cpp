class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int strLen = s.size();
		unordered_map<char,int> haveRead;
		int ans = 0, temp = 0;
		for (int i = 0; i < strLen; ++i) {
			if (haveRead.find(s[i]) == haveRead.end()) {
				haveRead.insert(make_pair(s[i],i));
				temp++;
			}
			else {
				i = haveRead.find(s[i])->second; // 注意循环结束会加一
				ans = max(ans, temp);
				temp = 0;
				haveRead.clear();
			}
		}
		ans = max(ans, temp);
		return ans;
	}
};