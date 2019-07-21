#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAXN 1005
#define MAXM 10005

int n, m; // µãÊý£¬±ßÊý

bool connected[MAXN][MAXN];

void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				connected[i][j] = connected[i][j] || (connected[i][k] && connected[k][j]);
			}
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		connected[x][y] = true;
	}
	for (int i = 1; i <= n; ++i) {
		connected[i][i] = true;
	}
	floyd();
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		bool connectAll = true;
		for (int j = 1; j <= n; ++j) {
			connectAll = connectAll && (connected[i][j] || connected[j][i]);
		}
		if (connectAll) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
