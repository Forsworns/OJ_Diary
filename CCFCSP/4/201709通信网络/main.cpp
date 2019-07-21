#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;

int n, m; // 点数，边数

bool connected[MAXN][MAXN] = { false };
vector<int> paths[MAXN];

void dfs(int to, bool visit[], int from) { // 已知相连的点
	if (visit[to]) {
		return;
	}
	visit[to] = true;
	connected[from][to] = true;
	connected[to][from] = true;
	for (auto node : paths[to]) { // 所有与to相连的点，也会和from互相已知
		dfs(node,visit,from);
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		paths[x].push_back(y);
		connected[x][y] = true;
	}
	for (int i = 1; i <= n; ++i) {
		connected[i][i] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n;++i) {
		bool visit[MAXN] = { false };
		dfs(i, visit, i);
	}
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
