#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;
const int MAXN = 1003;
const int INF = 1<<30;
int dp[MAXN][MAXN] = {0};
int freq[MAXN] = {0};
int sum[MAXN] = {0};

int main()
{
	freopen("test.txt","r",stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> freq[i];
		sum[i] = sum[i - 1] + freq[i];
	}
	for (int i = 2; i <= n; ++i) { // 合并的数字的区间长度
		for (int j = 1; j <= n - i +1; ++j) { // 起始位置
			dp[j][i+j-1] = INF; // 终止位置为i+j-1
			for (int k = j; k < i + j - 1;++k) {
				if (dp[j][i+j-1]>dp[j][k]+dp[k+1][i+j-1]+sum[i+j-1]-sum[j-1]) {
					dp[j][i + j - 1] = dp[j][k] + dp[k + 1][i + j - 1] + sum[i + j - 1] - sum[j - 1];
				}
			}
		}
	}
	cout << dp[1][n];
	return 0;
}
