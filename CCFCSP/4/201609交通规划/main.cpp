#pragma warning (disable:4996)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int MAXN = 1e4 + 233;
const int INF = 0x3f3f3f;
int n, m, ans;

int vis[MAXN], dist[MAXN], pre[MAXN], f[MAXN]; // 是否处理过该点， 到源点最短距离， 前驱的路径长度， 前驱点

struct node {
	int v;
	int c;
	node(int _v, int _c) :v(_v), c(_c) {}
	bool operator <(const node &a)const {
		return c > a.c;
	}
};

vector<node> g[MAXN];


void dijstra() {
	priority_queue<node> pq;
	pq.push(node(1, 0));
	while (!pq.empty()) {
		node tmp = pq.top();
		pq.pop();
		int u = tmp.v;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (dist[v] > tmp.c + g[u][i].c) {
					dist[v] = tmp.c + g[u][i].c;
					pre[v] = g[u][i].c;
					f[v] = u;
					pq.push(node(v, dist[v]));
				}
				else if (dist[v] == tmp.c + g[u][i].c) {
					if (g[u][i].c < pre[v]) {
						f[v] = u;
						pre[v] = g[u][i].c;
					}
				}
			}
		}
	}
}

void init() {
	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));
	for (int i = 2; i < MAXN; ++i)  dist[i] = INF;
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < MAXN; ++i) g[i].clear();
	dist[0] = dist[1] = ans = 0;
}

int main() {
	freopen("test.txt", "r", stdin);
	init();
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(node(v, c));
		g[v].push_back(node(u, c));
	}

	dijstra();
	for (int u = 1; u <= n;++u) {
		ans += (dist[u] - dist[f[u]]);  //这里需要注意，要减去之前的那段重复路径；不要用from/to区分边，因为可能有多个相同from->to的边
	}
	cout << ans;
	return 0;
}