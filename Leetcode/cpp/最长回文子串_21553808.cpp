class Solution {
private:
	bool **dp;
public:
    string longestPalindrome(string s) {
		int strLen = s.size();
		int maximum = 1;
		int l = 0;
		dp = new bool*[strLen];
		// 初始化
		for (int i = 0; i < strLen; ++i) {
			dp[i] = new bool[strLen]();
			dp[i][i] = true;
			if (i+1 < strLen) {
				if(s[i] == s[i+1]) {
					dp[i][i+1] = true;
					maximum = 2;
					l = i;
				}
				else {
					dp[i][i+1] = false;
				}
			}
		}
		for (int i = 2; i < strLen; ++i ) {
			for (int j = 0; j < strLen - i; ++j) {
				if (dp[j + 1][j + i - 1] && s[j]==s[j+i]) {
					dp[j][j+i] = true;
					if (i + 1 >maximum) {
						maximum = i + 1;
						l = j;
					}
				}
				else {
					dp[j][j + i] = false;
				}
			}
		}
		return s.substr(l,maximum);
	}
};